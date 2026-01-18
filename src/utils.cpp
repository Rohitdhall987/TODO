#include "utils.h"
#include "types.h"
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

void display_tasks(int start_row, uint16_t opt, std::vector<Task> &tasks) {
  std::string status;
  for (size_t i = 0; i < tasks.size(); i++) {

    switch (tasks[i].status) {
    case PENDING:
      status = "Pending";
      break;
    case ONGOING:
      status = "Ongoing";
      break;
    case COMPLETED:
      status = "Completed";
      break;
    default:
      status = "Pending";
    }

    mvprintw(start_row + i, 1, "TASK NAME: %s", tasks[i].Title.c_str());
    mvprintw(start_row + 1 + i, 1, "TASK DESCRIPTION: %s",
             tasks[i].Des.c_str());
    mvprintw(start_row + 2 + i, 1, "TASK STATUS: %s", status.c_str());
    mvprintw(start_row + 3 + i, 1,
             "------------------------------------------------------------");
  }
}
