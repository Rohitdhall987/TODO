#pragma once

#include <cstdint>
#include <string>

#define PENDING 0x00
#define ONGOING 0x01
#define COMPLETED 0x02

struct Task {
  uint16_t id;
  std::string Title;
  std::string Des;
  uint8_t status;
};
