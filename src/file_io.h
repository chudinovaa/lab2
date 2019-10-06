#ifndef LAB2_FILE_IO_H
#define LAB2_FILE_IO_H

#include <string>
#include <vector>

std::vector<std::string> read_file(const std::string &path);

void write_to_file(const std::string &path, const std::vector<std::string> &data);

#endif //LAB2_FILE_IO_H
