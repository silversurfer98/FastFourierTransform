cmake_minimum_required(VERSION 3.2)

project(FFT VERSION 1.0.3)

add_subdirectory(FFT)
add_subdirectory(dataPreparation)

add_executable(output main.cpp)

target_link_libraries(output PRIVATE dataprep)

