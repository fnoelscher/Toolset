#ifndef FILEOPS_HPP
#define FILEOPS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <dirent.h>

std::vector<std::string>
listDirectoryFiles(std::string path)
{
  DIR *dir;
  struct dirent *ent;
  std::vector<std::string> files;

  if ((dir = opendir (path.c_str())) != NULL) 
    {
      while ((ent = readdir (dir)) != NULL) 
	{
	  files.push_back( ((std::string) ent->d_name) );
	}
      closedir (dir);
    } else 
    {
      std::cerr << "Could not open directory!" << std::endl;
    }
  return files;
}

#endif
