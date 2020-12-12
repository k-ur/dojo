#ifndef FILE_LIST_H
#define FILE_LIST_H
#include <iostream>
#include <string>
#include <vector>

class File_list
{
public:
  File_list(std::string path, bool recursive);
  std::vector<std::string> get_file_list();
private:
  std::vector<std::string> files;
  std::vector<std::string> get_sub(std::string path);
};

#endif // FILE_LIST_H
