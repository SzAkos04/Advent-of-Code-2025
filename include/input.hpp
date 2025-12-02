#pragma once

#include <string>
#include <vector>
class Input {
  public:
    explicit Input(const std::string &filename_);

    std::vector<std::string> readLines() const;

    std::string readAll() const;

  private:
    std::string filename;
};
