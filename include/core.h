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

public:
  App();
  bool isRunning() const;
  void displayMainMenu(uint16_t &option);
  void displayViewTasks(uint16_t &option);
  void displayAddTask(uint16_t &option);
  void displayEditTask(uint16_t &option);
  void displayDeleteTask(uint16_t &option);
  void addTask(std::string title, std::string des);
  void exit();
};

#endif // TODO_CODE_H
