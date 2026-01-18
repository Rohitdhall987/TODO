//
// Created by rohit on 1/15/26.
//

#include "core.h"
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

  mvprintw(7, 1, "%d", opt);

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

void App::displayViewTasks(uint16_t &option) {}

void App::displayEditTask(uint16_t &option) {}

void App::displayAddTask(uint16_t &option) {}

void App::displayDeleteTask(uint16_t &option) {}

void App::addTask(std::string title, std::string des) {
  Task new_Task;
  new_Task.id = auto_id++;
  new_Task.Title = title;
  new_Task.Des = des;
  new_Task.status = PENDING;

  tasks.push_back(new_Task);
}

bool App::isRunning() const { return running; }

void App::exit() { running = false; }
