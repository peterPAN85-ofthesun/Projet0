#include "FileTools.hpp"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::vector<std::string> &
getFilesInDirectory(std::string const path,
                    std::vector<std::string> &listFiles) {

  fs::path directoryPath = path;

  try {
    for (const auto &entry : fs::recursive_directory_iterator(directoryPath)) {
      if (fs::is_regular_file(entry)) {
        listFiles.push_back(path + entry.path().filename().string());
      }
    }
  } catch (const fs::filesystem_error &e) {
    std::cerr << "Erreur: " << e.what() << std::endl;
  }

  return listFiles;
}

/*
using namespace std;

int main() {
  std::vector<std::string> list;
  getFilesInDirectory("/home/gregoire/Documents/Script/C++/Projet0/"
                      "raylib-game-template-main/src/resources/RayLibTest",
                      list);
  std::cout << list.size() << std::endl;
  for (long unsigned int i = 0; i < list.size(); i++) {
    std::cout << list[i] << std::endl;
  }

  return 0;
}
*/
