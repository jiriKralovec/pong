#pragma once
#include <iostream>

void LogMessage(const char* message, const char* file, unsigned int line);

#define LOG(m) LogMessage(m, __FILE__, __LINE__)