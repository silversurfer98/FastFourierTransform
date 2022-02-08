add_subdirectory(Trignometry)

add_library(
    fft
    fft.h
    fft.cpp
)

target_link_libraries(fft trig)

target_include_directories(fft PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")