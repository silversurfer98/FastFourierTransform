// used to prep data from txt files

#include "driver.h"

long int p = 1;

int No_of_line(const char filename[])
{
    std::ifstream myfile(filename);
    std::string line;
    int n = 0;
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, line);
            n++;
        }
        myfile.close();
    }
    return n;
}

unsigned int nearestPowerof2(unsigned int datasize)
{
//find the nearest power of 2
    //HINT -- left bit shift
    unsigned int t;
    for (int i = 1; i < 32; i++)
    {
        t = 1;
        t = t << i;
        if (t >= datasize)
            break;
    }
    return t;
}


data* alloc_array(unsigned int* n)
{
    data* x;
    *n = nearestPowerof2(*n);
    x = new data[*n];
    return x;
}

void getData(data* x, int n, const char filename_real[], const char filename_img[])
{
    std::ifstream input_real(filename_real);
    std::ifstream input_img(filename_img);
    if (input_real.peek() == std::ifstream::traits_type::eof())
    {
        for (int i = 0; i < n; i++)
            x[i].real = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (input_real.eof())
            x[i].real = 0;
        input_real >> x[i].real;
    }

    if (input_img.peek() == std::ifstream::traits_type::eof())
    {
        for (int i = 0; i < n; i++)
            x[i].imaginary = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (input_real.eof())
            x[i].imaginary = 0;
        input_img >> x[i].imaginary;
    }

}

void getdata(data* x, unsigned int n)
{
    std::cout << "Enter the real values :\n";
    for (unsigned int i = 0; i < n; i++)
        std::cin >> x[i].real;
    std::cout << "\n\n Do u have imaginary values (Y/n) : ";
    char c;
    std::cin >> c;
    if (c == 'y' || c == 'Y')
    {
        std::cout << "\n\nEnter the imaginary values :\n";
        for (unsigned int i = 0; i < n; i++)
            std::cin >> x[i].imaginary;
    }
    else
    {
        for (unsigned int i = 0; i < n; i++)
            x[i].imaginary = 0;
    }
}

data* prep_data_driver(unsigned int *n, unsigned int *original_n, int *data_flag)
{
    data* x;
    std::cout << "\n Do u want to get data from txt files [or are u gonna type it in console] (Y/n) : ";
    char choice;
    std::cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        int n_real = No_of_line(input_real);
        int n_imaginary = No_of_line(input_imaginary);
        if (n_real >= n_imaginary)
            *n = n_real;
        else
            *n = n_imaginary;

        *original_n = *n;
        x = alloc_array(n);
        getData(x, *n, input_real, input_imaginary);
        std::cout << "\n\n Got Data from text files \n\n";
        *data_flag = 1;
        return x;
    }

    else if (choice == 'N' || choice == 'n')
    {
        std::cout << "\n\n Getting Data from console \n\n";
        std::cout << "\n Enter the size of the data : ";
        std::cin >> *n;
        *original_n = *n;
        x = alloc_array(n);
        getdata(x, *original_n);
        for (unsigned int i = *original_n; i < *n; i++)
        {
            x[i].real = 0;
            x[i].imaginary = 0;
        }
        *data_flag = 1;
        return x;
    } 

    else
    {
        *data_flag = 0;
        return NULL;
    }
}