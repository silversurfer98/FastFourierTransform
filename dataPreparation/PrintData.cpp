#include "driver.h"

void printData(data* x, unsigned int n, unsigned int precision)
{
	std::cout << "\n\n *************** The Data Start ******************\n\n";
	for (unsigned int i = 0; i < n; i++)
	{
		if (x[i].imaginary == 0)
			std::cout << std::setprecision(precision) << x[i].real << "\n";
		else if (x[i].imaginary > 0)
			std::cout << std::setprecision(precision) << x[i].real << "+" << std::setprecision(precision) << x[i].imaginary << "i\n";
		else
			std::cout << std::setprecision(precision) << x[i].real << "" << std::setprecision(precision) << x[i].imaginary << "i\n";
	}
	std::cout << "\n\n***************** End of data **********************\n\n";

}

void printData2File(data* x, unsigned int n, unsigned int precision)
{
	std::ofstream result("result.txt");
	result << "\n\n *************** The Data Start ******************\n\n";
	for (unsigned int i = 0; i < n; i++)
	{
		if (x[i].imaginary == 0)
			result << std::setprecision(precision) << x[i].real << "\n";
		else if (x[i].imaginary > 0)
			result << std::setprecision(precision) << x[i].real << "+" << std::setprecision(precision) << x[i].imaginary << "i\n";
		else
			result << std::setprecision(precision) << x[i].real << "" << std::setprecision(precision) << x[i].imaginary << "i\n";
	}
	result << "\n\n***************** End of data **********************\n\n";

}
