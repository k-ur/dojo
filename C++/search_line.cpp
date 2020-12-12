#include "search_line.h"
#include <fstream>

Search_line::Search_line(std::string path ,std::string keyword)
{
  std::ifstream ifs(path);
  std::string str;
  if (ifs.fail()) {
    std::cerr << "Failed to open file." << std::endl;
  }
  file_path = path;
  unsigned long line = 0;
  while (getline(ifs, str)) {
    if (str.find(keyword) != std::string::npos)
    {
      detect detect_line = {line,str};
      detect_lines.push_back(detect_line);
    }
    line++;
  }
}
void Search_line::display()
{
  for(detect detect_line : detect_lines)
  {
    std::cout << file_path << " " << detect_line.line << " " << detect_line.str << std::endl;
  }
}

