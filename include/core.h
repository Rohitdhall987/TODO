//
// Created by rohit on 1/15/26.
//

#ifndef TODO_CODE_H
#define TODO_CODE_H

#include "types.h"
#include <cstdint>
#include <string>
#include <vector>

class App {
  uint32_t auto_id;
  bool running = false;
  std::vector<Task> tasks;

  void addTask(std::string title, std::string des);
  void deleteTask(size_t index);
  void updateStatus(Task &t);
  void updateTask(size_t index, std::string t, std::string d);

public:
  App();
  bool isRunning() const;
  void displayMainMenu(uint16_t &option);
  void displayViewTasks(uint16_t &option);
  void displayAddTask(uint16_t &option);
  void displayEditTask(uint16_t &option);
  void displayDeleteTask(uint16_t &option);
  void exit();
};

#endif // TODO_CODE_H
