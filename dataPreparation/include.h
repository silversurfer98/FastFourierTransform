#pragma once
#include<iostream>
#include<fstream>
#include <iomanip>
#include<string>
#include "..\FFT\fft.h"

typedef complexNumbers data;

/* text files --> filenames
files are splitted into 2 parts 
put real values in real.txt
and imaginary parts in imaginary.txt
if no imaginary just dont input any 
*/
const char input_real[] = "input_data_real_values.txt";
const char input_imaginary[] = "input_data_imaginary_values.txt";

// used to log values
void printData(data* x, unsigned int n, unsigned int precision);
void printData2File(data* x, unsigned int n, unsigned int precision);

// data preparation for fft
data* prep_data_driver(unsigned int* n, unsigned int* original_n, int *data_flag);
void fft_driver(data* x, unsigned int n, unsigned int display_number_precision);