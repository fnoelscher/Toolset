#include "fileops.hpp"

int main(int argc, char **argv)
{
  std::vector<std::string> dirContents = listDirectoryFiles("testdir");

  for(std::string s : dirContents)
    {
      std::cout << s << std::endl;
    }

  return 0;
}
