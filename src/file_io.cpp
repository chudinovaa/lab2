#include "file_io.h"

#include <fstream>

std::vector<std::string> read_file(const std::string &path)
{
  std::ifstream stream;
  stream.open(path);
  std::vector<std::string> data;
  if(stream.is_open())
  {
    std::string line;
    while (std::getline(stream, line))
    {
      data.push_back(std::move(line));
    }
  }
  return data;
}

void write_to_file(const std::string &path, const std::vector<std::string> &data)
{
  std::ofstream stream;
  stream.open(path, std::ios::out | std::ios::trunc);
  if (stream.is_open())
  {
    for(const auto &line : data)
    {
      stream << line << std::endl;
    }
  }
}
