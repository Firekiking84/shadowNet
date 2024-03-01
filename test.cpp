#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>

int main()
{
  const std::filesystem::path sandbox{"src"};

  std::cout << "directory_iterator:\n";
  // directory_iterator can be iterated using a range-for loop
  for (auto const& dir_entry : std::filesystem::directory_iterator{sandbox})
    std::cout << dir_entry.path() << '\n';

  std::cout << "\nrecursive_directory_iterator:\n";
  for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{sandbox})
    std::cout << dir_entry << '\n';
}
