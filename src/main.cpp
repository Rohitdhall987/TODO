
#include "core.h"
#include <ncurses.h>

int main() {
  App app{};

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  uint16_t option = 0;
  while (app.isRunning()) {
    clear();

    mvprintw(0, 0, "Simple TO-DO app!");
    mvprintw(1, 0, "Q(EXIT) UP/DOWN(MOVE) SPACE(SELECT) ESC(BACK)");

    switch (option) {
    case 0:
      app.displayMainMenu(option);
      break;

    case 1:
      app.displayViewTasks(option);
      break;

    case 2:
      app.displayAddTask(option);
      break;

    case 3:
      app.displayEditTask(option);
      break;

    case 4:
      app.displayDeleteTask(option);
      break;

    default:
      app.displayMainMenu(option);
      break;
    }
    refresh();
  }

  endwin();
  return 0;
}
