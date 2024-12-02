cmake_minimum_required(VERSION 3.30.0)
project(Project-2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

# executable
add_executable(${PROJECT_NAME} "src/main.cpp")

# dirs
add_subdirectory(include)
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} include)
target_link_libraries(${PROJECT_NAME} src)