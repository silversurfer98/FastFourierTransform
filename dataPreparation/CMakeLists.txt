include_directories(../FFT)

add_library(
    dataprep
    driver.h
    data_prep.cpp
    fft_driver.cpp
    PrintData.cpp
)

target_link_libraries(dataprep fft)

target_include_directories(dataprep PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")