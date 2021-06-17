#include "file.h"
#include <cerrno>
#include <cstring>
#include <iostream>

FILE* openFileOrFail(const char* path, const char* mode)
{
    FILE* file = fopen(path, mode);
    if(file == nullptr)
        std::cout << "Failed to open '" << path << "': " << strerror(errno) << std::endl;
    return file;
}