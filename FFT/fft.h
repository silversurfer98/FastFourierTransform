#pragma once
#include "..\Trignometry-101\Trig_funcs.h"
//#include<iostream>
struct complexNumbers
{
    double real = 0, imaginary = 0;
    ~complexNumbers()
    {
        //std::cout<<"\n\n\n\ndeleted !\n\n\n\n";
    }
};
typedef complexNumbers data;

void fft(data* x, unsigned int n);
void ifft(data* x, unsigned int n);