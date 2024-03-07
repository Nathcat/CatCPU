cmake_minimum_required(VERSION 3.22.1)

project(CatCPU)

add_executable(CatCPU src/CatCPU.cpp)
target_include_directories(CatCPU PUBLIC include)
set_target_properties(CatCPU PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY build)