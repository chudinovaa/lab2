#include "file_io.h"
#include "sort.h"

int main()
{
  auto data = read_file("abc.txt");
  for(auto &line : data)
    line = sort(line);
  write_to_file("sorted.txt", data);
  return 0;
}
