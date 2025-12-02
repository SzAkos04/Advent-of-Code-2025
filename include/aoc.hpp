#pragma once

#include <functional>

namespace aoc {
using DayFunc = std::function<void()>;

void registerDay(int index, DayFunc func);
void run(int day);
} // namespace aoc
