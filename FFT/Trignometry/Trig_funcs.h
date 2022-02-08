#pragma once
#include<stdlib.h>
class trignometry
{
public:
    double invf[21] =
    {
        1.000000000000000E+00,
        1.000000000000000E+00,
        5.000000000000000E-01,
        1.666666666666670E-01,
        4.166666666666670E-02,
        8.333333333333330E-03,
        1.388888888888890E-03,
        1.984126984126980E-04,
        2.480158730158730E-05,
        2.755731922398590E-06,
        2.755731922398590E-07,
        2.505210838544170E-08,
        2.087675698786810E-09,
        1.605904383682160E-10,
        1.147074559772970E-11,
        7.647163731819820E-13,
        4.779477332387390E-14,
        2.811457254345520E-15,
        1.561920696858620E-16,
        8.220635246624330E-18,
        4.110317623312160E-19
    };
    int iter, pof1;
    char c;
    double p, s, PI, sign;
    trignometry(int iterations, char choice);
    double mypower(double base, int exp);
    void rad2rad(double* rad);
    void deg2rad(double* deg);
    double sin(double x);
    double cos(double x);
};