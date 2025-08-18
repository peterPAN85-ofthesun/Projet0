#ifndef FILETOOLS_HPP
#define FILETOOLS_HPP

#include <string>
#include <vector>

std::vector<std::string> &
getFilesInDirectory(std::string const path,
                    std::vector<std::string> &listFiles);

#endif // !FILETOOLS_HPP
