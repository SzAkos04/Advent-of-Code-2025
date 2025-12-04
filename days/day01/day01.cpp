#include "day01.hpp"

#include "aoc.hpp"
#include "input.hpp"

#include <iostream>
#include <string>

static bool registered = (aoc::registerDay(1, run_day01), true);

void day01_1();
void day01_2();

void run_day01() {
    day01_1();
    day01_2();
}

void day01_1() {
    Input input("input/day01.txt");
    auto lines = input.readLines();

    int dial = 50;
    int zeros = 0;

    for (const auto &line : lines) {
        int value = std::stoi(line.substr(1));
        dial += line[0] == 'R' ? value : -value;

        dial = (dial % 100 + 100) % 100;

        if (dial == 0) {
            zeros++;
        }
    }

    std::cout << "Answer: " << zeros << std::endl;
}

void day01_2() {
    Input input("input/day01.txt");
    auto lines = input.readLines();

    int dial = 50;
    int clicks = 0;

    for (const auto &line : lines) {
        int value = std::stoi(line.substr(1));
        int dir = line[0] == 'R' ? 1 : -1;

        for (int i = 0; i < value; ++i) {
            dial += dir;
            if (dial > 99) {
                dial = 0;
            } else if (dial < 0) {
                dial = 99;
            }

            if (dial == 0) {
                clicks++;
            }
        }
    }

    std::cout << "Answer: " << clicks << std::endl;
}
