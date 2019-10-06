#include <gtest/gtest.h>

#include <src/sort.h>

#include <random>

TEST(testSort, sort_empty)
{
  std::string empty;
  auto sorted = sort(empty);
  ASSERT_TRUE(empty.empty());
}

TEST(testSort, sort_already_sorted)
{
  std::string str{"abcde"};
  auto sorted = sort(str);
  ASSERT_EQ(str, "abcde");
}

TEST(testSort, sort_inverse_string)
{
  std::string str{"edcba"};
  auto sorted = sort(str);
  ASSERT_EQ(sorted, "abcde");
}

TEST(testSort, sort_with_duplicate_symbols)
{
  std::string str{"abcbede"};
  auto sorted = sort(str);
  ASSERT_EQ(sorted, "abbcdee");
}

TEST(testSort, sort_random)
{
  const std::string chars = "abcdefghijklmnaoqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  const int length = 15;

  for (int i = 0; i < 100; ++i)
  {
    std::mt19937_64 generator{std::random_device()()};
    std::uniform_int_distribution<size_t> dist{0, chars.length() - 1};
    std::string string;
    std::generate_n(std::back_inserter(string), length,
                    [&]
                    {
                      return chars[dist(generator)];
                    });

    auto sorted = sort(string);

    for (size_t j = 0; j < string.length() - 1; ++j)
    {
      bool lessEqual = sorted[j] <= sorted[j + 1];
      EXPECT_TRUE(lessEqual) << "Test #" << i << std::endl << sorted <<
                             ": unsorted sequence after symbol " << j << std::endl;
      if (lessEqual)
        break;
    }
  }
}
