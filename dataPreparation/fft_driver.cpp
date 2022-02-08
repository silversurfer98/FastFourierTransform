#include "driver.h"

void fft_driver(data* x, unsigned int n, unsigned int display_number_precision)
{
	std::cout << "\n\n*********** This is a open source FFT module *******************\n\n";
	std::cout << "\n\n should i call fft or ifft\n 1.FFT\n 2.IFFT\n Yout choice --> ";
	int p;
	std::cin >> p;
	if (p == 1)
		fft(x, n);
	else if (p == 2)
		ifft(x, n);
	else
		return;
	printData2File(x, n, display_number_precision);
	std::cout << "\n\n should i display results in console (Y/n) : ";
	char c;
	std::cin >> c;
	if (c == 'y' || c == 'Y')
	{
		printData(x, n, display_number_precision);
		std::cout << "\n\n ********* Exiting the module, Bye xD *********\n\n";
	}
	else
	{
		std::cout << "\n\n ********* Exiting the module, Bye xD *********\n\n";
		return;
	}
	// this sinle line defines the heap de allocation
	delete[] x;

}