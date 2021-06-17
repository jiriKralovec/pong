cmake_minimum_required(VERSION 3.17)
project(pong)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp source/util/logger.h source/renderer.h source/renderer.cpp source/util/logger.cpp source/input.h source/input.cpp source/shader.h source/shader.cpp source/util/file.h source/util/file.cpp source/abstract/shape.cpp source/abstract/shape.h source/triangle.h source/abstract/game-object.h source/object-store.h source/object-store.cpp source/abstract/game-object.cpp)

# Copy resources
##add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
##        COMMAND ${CMAKE_COMMAND} -E copy_directory
##        ${CMAKE_SOURCE_DIR}/source/shaders/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders/)

# Add subdirectories
add_subdirectory(glew-2.1.0/build/cmake)
add_subdirectory(glfw)
add_subdirectory(glm)

# Include public API
target_include_directories(${PROJECT_NAME}
    PUBLIC glfw/include
    PUBLIC glew-2.1.0/include
    PUBLIC glm/glm
)

# Link directories for library lookup
target_link_directories(${PROJECT_NAME}
    PRIVATE glew
    PRIVATE glfw-2.1.0
    PRIVATE glm
)

# Lookup libraries
target_link_libraries(${PROJECT_NAME} glm glew_s glfw)