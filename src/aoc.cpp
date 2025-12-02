#include "aoc.hpp"
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace {
std::unordered_map<int, aoc::DayFunc> registry;
}

namespace aoc {
void registerDay(int index, DayFunc func) { registry[index] = std::move(func); }

void run(int day) {
    if (!registry.contains(day)) {
        throw std::runtime_error("Day " + std::to_string(day) +
                                 " not implemented");
    }
    registry[day]();
}
} // namespace aoc
