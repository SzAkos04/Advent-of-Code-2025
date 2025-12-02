#include "aoc.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

int main(int argc, char **argv) {
    try {
        if (argc < 2) {
            throw std::runtime_error("Incorrect usage");
        }

        int day = std::stoi(argv[1]);
        aoc::run(day);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
