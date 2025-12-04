#include "day03.hpp"

#include "aoc.hpp"
#include "input.hpp"

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

static bool registered = (aoc::registerDay(3, run_day03), true);

void day03_1();
void day03_2();

void run_day03() {
    day03_1();
    day03_2();
}

void day03_1() {
    Input input("input/day03.txt");
    std::vector<std::string> lines = input.readLines();

    int total = 0;

    for (const auto &line : lines) {
        int max_number = 0;

        for (size_t tens_pos = 0; tens_pos < line.size() - 1; ++tens_pos) {
            int tens = line[tens_pos] - '0';

            for (size_t ones_pos = tens_pos + 1; ones_pos < line.size();
                 ++ones_pos) {
                int ones = line[ones_pos] - '0';
                int number = tens * 10 + ones;
                if (number > max_number) {
                    max_number = number;
                }
            }
        }

        total += max_number;
    }

    std::cout << "Answer: " << total << std::endl;
}

// FIXME: Incorrect
void day03_2() {
    Input input("input/day03.txt");
    std::vector<std::string> lines = input.readLines();

    unsigned long long total = 0;

    for (const auto &line : lines) {
        std::vector<int> digits;
        size_t start = 0;
        const int N = 12;
        for (int i = N; i >= 1; --i) {
            int max_digit = -1;
            size_t max_pos = start;

            size_t end_limit = line.size() - i;

            for (size_t pos = start; pos <= end_limit; ++pos) {
                int digit = line[pos] - '0';
                if (digit > max_digit) {
                    max_digit = digit;
                    max_pos = pos;
                }
            }
            digits.push_back(max_digit);
            start = max_pos + 1;
        }

        unsigned long long number = 0;
        for (int d : digits) {
            number = number * 10 + d;
        }

        total += number;
    }

    std::cout << "Answer: " << total << std::endl;
}
