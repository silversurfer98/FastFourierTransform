#pragma once
#include "..\Trignometry-101\Trig_funcs.h"

struct complexNumbers
{
    double real = 0, imaginary = 0;
};
typedef complexNumbers data;

void fft(data* x, unsigned int n);
void ifft(data* x, unsigned int n);