#include <cmath>
#include <string>

template<typename Iterator>
void shell_sort(Iterator begin, Iterator end)
{
  auto container_size = std::distance(begin, end);
  for (auto dist = container_size / 2; dist >= 1; dist /= 2)
  {
    for(Iterator i = begin + dist; i != end; ++i)
      for(Iterator j = i; (j >= begin + dist) && (*j <= *(j - dist)); j -= dist)
        std::swap(*j, *(j - dist));
  }
}

std::string sort(const std::string &data)
{
  std::string string = data;
  shell_sort(std::begin(string), std::end(string));
  return string;
}
