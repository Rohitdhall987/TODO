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
  for (size_t i = 0; i < tasks.size(); i++) {

    int row = start_row + i * 4;

    std::string status;
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

    if (opt == i)
      attron(A_REVERSE);

    mvprintw(row + 0, 1, "TASK NAME: %s", tasks[i].Title.c_str());
    mvprintw(row + 1, 1, "TASK DESCRIPTION: %s", tasks[i].Des.c_str());
    mvprintw(row + 2, 1, "TASK STATUS: %s", status.c_str());
    mvprintw(row + 3, 1,
             "------------------------------------------------------------");

    if (opt == i)
      attroff(A_REVERSE);
  }
}

void to_json(json &j, const Task &t) {
  j = json{{"id", t.id},
           {"title", t.Title},
           {"description", t.Des},
           {"status", t.status}};
}

void from_json(const json &j, Task &t) {
  j.at("id").get_to(t.id);
  j.at("title").get_to(t.Title);
  j.at("description").get_to(t.Des);

  t.status = j.value("status", PENDING);
}
