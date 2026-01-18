#pragma once
#include <cstdint>
#include <string>
#include <vector>

#include "types.h"

void display_options(int start_raw, uint16_t opt,
                     std::vector<std::string> options);

void display_tasks(int start_raw, uint16_t opt, std::vector<Task> &tasks);
