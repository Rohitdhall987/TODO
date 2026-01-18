//
// Created by rohit on 1/15/26.
//

#include "core.h"
#include "types.h"
#include "utils.h"
#include <cstdint>
#include <curses.h>
#include <ncurses.h>

App::App() {
  running = true;
  tasks = {};
  auto_id = 0;
}

void App::displayMainMenu(uint16_t &option) {
  static uint8_t opt;
  const std::vector<std::string> options = {"VIEW TASKS", "ADD TASKS",
                                            "EDIT TASKS", "DELETE TASKS"};

  display_options(3, opt - 1, options);

  switch (getch()) {
  case 'Q':
  case 'q':
    this->exit();
    break;

  case ' ':
    option = opt;
    break;

  case KEY_UP:
    if (opt > 1)
      opt--;
    break;

  case KEY_DOWN:
    if (opt < options.size())
      opt++;
    break;
  default:;
  }
}

void App::displayViewTasks(uint16_t &option) {
  static size_t opt;

  if (tasks.size()) {
    display_tasks(3, opt, tasks);
  } else {
    mvprintw(3, 1, "YOU HAVE NO TASKES TO DO!");
  }

  switch (getch()) {
  case 'q':
  case 'Q':
    this->exit();
    break;
  case 27:
    option = 0;
    break;
  case ' ':
    this->updateStatus(tasks[opt]);
    break;
  case KEY_UP:
    if (opt > 0)
      opt--;
    break;
  case KEY_DOWN:
    if (opt < tasks.size() - 1)
      opt++;
    break;
  default:;
  }
}

void App::displayEditTask(uint16_t &option) {

  static size_t opt;

  if (tasks.size()) {
    display_tasks(3, opt, tasks);
  } else {
    mvprintw(3, 1, "YOU HAVE NO TASKES TO DO!");
  }

  switch (getch()) {
  case 'q':
  case 'Q':
    this->exit();
    break;
  case 27:
    option = 0;
    break;
  case ' ':
    option = 5;
    break;
  case KEY_UP:
    if (opt > 0)
      opt--;
    break;
  case KEY_DOWN:
    if (opt < tasks.size() - 1)
      opt++;
    break;
  default:;
  }
}

void App::displayAddTask(uint16_t &option) {
  echo();
  curs_set(1);

  char buff[256];

  mvprintw(3, 0, "Enter Task info");
  mvprintw(4, 0, "Enter Title: ");

  getnstr(buff, sizeof(buff) - 1);
  std::string t(buff);

  mvprintw(5, 0, "Enter Descritption:");

  getnstr(buff, sizeof(buff) - 1);
  std::string d(buff);

  this->addTask(t, d);

  noecho();
  curs_set(0);

  option = 0;
}

void App::displayDeleteTask(uint16_t &option) {
  static size_t opt;

  if (tasks.size()) {
    display_tasks(3, opt, tasks);
  } else {
    mvprintw(3, 1, "YOU HAVE NO TASKES TO DO!");
  }

  switch (getch()) {
  case 'q':
  case 'Q':
    this->exit();
    break;
  case 27:
    option = 0;
    break;
  case ' ':
    this->deleteTask(opt);
    break;
  case KEY_UP:
    if (opt > 0)
      opt--;
    break;
  case KEY_DOWN:
    if (opt < tasks.size() - 1)
      opt++;
    break;
  default:;
  }
}

void App::addTask(std::string title, std::string des) {
  Task new_Task;
  new_Task.id = auto_id++;
  new_Task.Title = title;
  new_Task.Des = des;
  new_Task.status = PENDING;

  tasks.push_back(new_Task);
}

void App::deleteTask(size_t index) { tasks.erase(tasks.begin() + index); }

void App::updateStatus(Task &t) {

  if (t.status == COMPLETED) {
    t.status = PENDING;
  } else {
    t.status++;
  }
}

bool App::isRunning() const { return running; }

void App::exit() { running = false; }
