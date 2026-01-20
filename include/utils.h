#pragma once
#include <cstdint>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
using json = nlohmann::json;

#include "types.h"

void display_options(int start_raw, uint16_t opt,
                     std::vector<std::string> options);

void display_tasks(int start_raw, uint16_t opt, std::vector<Task> &tasks);

void to_json(json &j, const Task &t);
void from_json(const json &j, Task &t);
