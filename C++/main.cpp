#include <iostream>
#include "file_list.h"
#include "search_line.h"

using namespace std;

int main(int argc, char* argv[])
{
  bool recursive = false;
  std::string keyword = "";
  std::string path = "";
  for(int i=1;i<argc;i++)
  {
    std::string str = argv[i];
    if ("-r" == str)
    {
      recursive = true;
    }
    else
    {
      if(i+1 < argc-1)
      {
        std::cout << "　Not enough arguments" <<std::endl;
        exit(-1);
      }
      keyword = argv[i];
      path = argv[i+1];
      break;
    }
  }

  File_list file_list = File_list(path,recursive);
  std::vector<std::string> files = file_list.get_file_list();
  for(std::string file:files)
  {
   Search_line search_line = Search_line(file, keyword);
   search_line.display();
  }
}
