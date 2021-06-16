#pragma once
#include <iostream>


#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GlClearError(); \
x;                                  \
ASSERT(GlLogCall(#x, __FILE__, __LINE__))
#define LOG(m) LogMessage(m, __FILE__, __LINE__)


void LogMessage(const char* message, const char* file, uint16_t line);
void GlClearError();
bool GlLogCall(const char* fn, const char* file, uint16_t line);