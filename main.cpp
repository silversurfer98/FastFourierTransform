// input file names are in include.h file rename that to modify.
// ********* i dont know what to say ********** will arise if u give no data to work with

#include <driver.h>

int main()
{   
    std::cout << "\n\n*** Before moving further make sure u read Read Me  ***\n\n";
    std::cout << "\n\n*** This code computes FOURIER TRANSFORM for given data  ***\n\n";
    unsigned int display_number_precision = 15;
    unsigned int n, original_n;
    int data_flag = 0;

    data* x = prep_data_driver(&n, &original_n, &data_flag);

    if (n == 0 || n == 1 || original_n == 0 || original_n == 1)
    {
        std::cout << "\n\n ********* i dont know what to say ********** \n\n";
        return 0;
    }

    if (data_flag != 0)
    {
        //printData(x, n, 10);
        fft_driver(x, n, display_number_precision);
    }
    else
        std::cout << "\n\n ********* i dont know what to say ********** \n\n";

    return 0;
}