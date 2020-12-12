#include <sys/stat.h>
#include <dirent.h>
#include "file_list.h"

File_list::File_list(std::string path, bool recursive)
{
  struct stat st;
  if(!stat(path.c_str(), &st))
  {
    switch(st.st_mode & S_IFMT)
    {
    case S_IFREG:  // file
      files.push_back(path);
      break;
    case S_IFDIR:  // directory
      if(recursive)
      {
        std::vector<std::string>sub_list = get_sub(path);
        for(std::string sub : sub_list)
        {
          File_list sub_file_list = File_list(path+"/"+sub,recursive);
          std::vector<std::string>temp_list = sub_file_list.get_file_list();
          files.insert(files.end(), temp_list.begin(), temp_list.end());
        }
        break;
      }
    }
  }
}

std::vector<std::string> File_list::get_file_list()
{
  return files;
}

std::vector<std::string> File_list::get_sub(std::string path)
{
  std::vector<std::string> sub_list;
  DIR *dp;
  dp = opendir(path.c_str());
  if (dp==NULL) exit(1);
  dirent* entry = readdir(dp);
  while (entry != NULL)
  {
    if (entry != NULL)
    {
      std::string name = entry->d_name;
      if(("." != name)and(".." != name))
      {
        sub_list.push_back(entry->d_name);
      }
    }
    entry = readdir(dp);
  }
  return sub_list;
}
