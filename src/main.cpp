
#include "core.h"
#include "utils.h"

#include <ncurses.h>
#include <stdint.h>
#include <string>
#include <vector>

int main() {
  App app{};

  uint8_t option = 0;
  const std::vector<std::string> options = {"VIEW TASKS", "ADD TASKS",
                                            "EDIT TASKS", "DELETE TASKS"};

  int input;

  // ncurses init
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  while (app.isRunning()) {
    clear();

    mvprintw(0, 0, "Simple TO-DO app!");
    mvprintw(1, 0, "Q(EXIT) UP/DOWN(MOVE) SPACE(SELECT)");

    display_options(3, option, options);
    refresh();

    input = getch();

    switch (input) {
    case 'Q':
    case 'q':
      app.exit();
      break;

    case KEY_UP:
      if (option > 0)
        option--;
      break;

    case KEY_DOWN:
      if (option < options.size() - 1)
        option++;
      break;
    }
  }

  endwin();
  return 0;
}
