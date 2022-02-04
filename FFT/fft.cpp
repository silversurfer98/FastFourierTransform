#include "fft.h"

void divide_conquer(data* x, data *even, data *odd, unsigned int n)
{
	// x is the parent array and n is the size of parent array
	for (unsigned int i = 0; i < n / 2; i++)
	{
		even[i].real = x[2 * i].real;
		even[i].imaginary = x[2 * i].imaginary;

		odd[i].real = x[2 * i + 1].real;
		odd[i].imaginary = x[2 * i + 1].imaginary;
	}

}

data *wn(int j, unsigned int n)
{
	data *w = new data;
	trignometry t(10, 'r');
	w->real = t.cos(-2 * t.PI * j / n);
	w->imaginary = t.sin(-2 * t.PI * j / n);

	return w;
	delete w;
}

// pass by reference
data* multipy_me(data *a, data *b)
{
	data* result = new data;
	result->real = a->real * b->real - a->imaginary * b->imaginary;
	result->imaginary = a->real * b->imaginary + b->real * a->imaginary;

	return result;
	delete result;
}

data* add_me(data *a, data *b)
{
	data* result = new data;

	result->real = a->real + b->real;
	result->imaginary = a->imaginary + b->imaginary;

	return result;
	delete result;
}

data* sub_me(data *a, data *b)
{
	data* result = new data;

	result->real = a->real - b->real;
	result->imaginary = a->imaginary - b->imaginary;

	return result;
	delete result;
}

void fft(data* x, unsigned int n)
{
	if (n == 1)
		return;

	data* even = new data[n / 2];
	data* odd = new data[n / 2];
	divide_conquer(x, even, odd, n);

	fft(even, n / 2);
	fft(odd, n / 2);

	for (unsigned int j = 0; j < n / 2; j++)
	{
		//data* t1 = new data;
		data* t2 = new data;
		data* t3 = new data;

		//t1 = multipy_me(wn(j, n), &odd[j]);
		t2 = add_me(&even[j], multipy_me(wn(j, n), &odd[j]));
		t3 = sub_me(&even[j], multipy_me(wn(j, n), &odd[j]));

		x[j].real = t2->real;
		x[j].imaginary = t2->imaginary;

		x[j + n / 2].real = t3->real;
		x[j + n / 2].imaginary = t3->imaginary;

		//delete t1;
		delete t2;
		delete t3;
	}

	delete[] even;
	delete[] odd;
}

void conjugate(data* x, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		x[i].imaginary = -1 * x[i].imaginary;
}

void ifft(data* x, unsigned int n)
{
	conjugate(x, n);
	fft(x, n);
	conjugate(x, n);

	for (unsigned int i = 0; i < n; i++)
		x[i].real = x[i].real / n;
}