#include "utils.h"
#include <ncurses.h>

void display_options(int start_row, uint16_t opt,
                     std::vector<std::string> options) {

  for (size_t i = 0; i < options.size(); i++) {
    if (opt == i) {
      attron(A_REVERSE);
      mvprintw(start_row + i, 0, "> %s", options[i].c_str());
      attroff(A_REVERSE);
    } else {
      mvprintw(start_row + i, 0, "  %s", options[i].c_str());
    }
  }
}
