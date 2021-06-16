cmake_minimum_required(VERSION 3.17)
project(pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp source/util/logger.h source/renderer.h source/renderer.cpp source/util/logger.cpp source/input.h source/input.cpp source/shader.h source/shader.cpp)

# Add subdirectories
add_subdirectory(glew-2.1.0/build/cmake)
add_subdirectory(glfw)

# Include public API
target_include_directories(${PROJECT_NAME}
    PUBLIC glfw/include
    PUBLIC glew-2.1.0/include
)

# Link directories for library lookup
target_link_directories(${PROJECT_NAME}
    PRIVATE glew
    PRIVATE glfw-2.1.0
)

# Lookup libraries
target_link_libraries(${PROJECT_NAME} glew_s glfw)