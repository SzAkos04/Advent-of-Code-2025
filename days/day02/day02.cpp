#include "day02.hpp"

#include "aoc.hpp"
#include "input.hpp"

#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

static bool registered = (aoc::registerDay(2, run_day02), true);

void day02_1();
void day02_2();

bool isInvalid1(unsigned long long n);
bool isInvalid2(unsigned long long n);

void run_day02() {
    day02_1();
    day02_2();
}

void day02_1() {
    Input input("input/day02.txt");
    std::string src = input.readAll();

    unsigned long long total = 0;

    std::stringstream ss(src);
    std::string str;
    while (std::getline(ss, str, ',')) {
        size_t dash = str.find('-');
        if (dash == std::string::npos) {
            continue;
        }

        unsigned long long a = std::stoull(str.substr(0, dash));
        unsigned long long b = std::stoull(str.substr(dash + 1));

        for (unsigned long long i = a; i <= b; ++i) {
            if (isInvalid1(i)) {
                total += i;
            }
        }
    }

    std::cout << "Answer: " << total << std::endl;
}

void day02_2() {
    Input input("input/day02.txt");
    std::string src = input.readAll();

    unsigned long long total = 0;

    std::stringstream ss(src);
    std::string str;
    while (std::getline(ss, str, ',')) {
        size_t dash = str.find('-');
        if (dash == std::string::npos) {
            continue;
        }

        unsigned long long a = std::stoull(str.substr(0, dash));
        unsigned long long b = std::stoull(str.substr(dash + 1));

        for (unsigned long long i = a; i <= b; ++i) {
            if (isInvalid2(i)) {
                total += i;
            }
        }
    }

    std::cout << "Answer: " << total << std::endl;
}

bool isInvalid1(unsigned long long n) {
    std::string str = std::to_string(n);
    int len = str.length();
    if (len % 2 != 0) {
        return false;
    }
    return str.substr(0, len / 2) == str.substr(len / 2, len / 2);
}

bool isInvalid2(unsigned long long n) {
    std::string str = std::to_string(n);
    int len = str.length();

    for (int i = 1; i <= len / 2; ++i) {
        if (len % i != 0) {
            continue;
        }

        int j = len / i;
        if (j < 2) {
            continue;
        }

        std::string pattern = str.substr(0, i);
        bool ret = true;

        for (int k = 1; k < j; ++k) {
            if (str.substr(k * i, i) != pattern) {
                ret = false;
                break;
            }
        }
        if (ret) {
            return true;
        }
    }
    return false;
}
