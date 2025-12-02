#include "input.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

Input::Input(const std::string &filename_) : filename(filename_) {}

std::vector<std::string> Input::readLines() const {
    std::ifstream infile(this->filename);
    if (!infile.is_open()) {
        throw std::runtime_error("Failed to open `" + this->filename + "`");
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(infile, line)) {
        lines.push_back(line);
    }

    infile.close();

    return lines;
}

std::string Input::readAll() const {
    std::ifstream infile(this->filename);
    if (!infile.is_open()) {
        throw std::runtime_error("Failed to open `" + this->filename + "`");
    }

    std::ostringstream ss;
    ss << infile.rdbuf();

    infile.close();

    return ss.str();
}
