#include "logger.h"

void LogMessage(const char* message, const char* file, const unsigned int line)
{
    std::cout << file << ":" << line << " " << message << std::endl;
}