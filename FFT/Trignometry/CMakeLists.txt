add_library(
    trig
    Trig_funcs.h
    Trignometry_funcs.cpp
)

target_include_directories(trig PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")