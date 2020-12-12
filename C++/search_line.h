#ifndef SEARCH_LINE_H
#define SEARCH_LINE_H
#include <iostream>
#include <string>
#include <vector>

class Search_line
{
public:
  Search_line(std::string path ,std::string keyword);
  void display();
private:
  std::string file_path;
  struct detect
  {
    unsigned long line;
    std::string str;
  };
  std::vector<detect> detect_lines;
};

#endif // SEARCH_LINE_H
