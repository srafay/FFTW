#include <fftw3.h>
#include <iostream>
#include <cmath>

using namespace std;

// Macros for real and imaginary parts
#define REAL 0
#define IMAG 1

int main()
{
	// Define the length of the complex arrays
	const int n=5;
	// Input array
	fftw_complex x[n]; // This is equivalent to double x[n][2];
	// Output array
	fftw_complex y[n]; // This is equivalent to double x[n][2];
	// Fill the first array with some data
	for (int i=0; i<n; i++)
	{
		x[i][REAL] = i+1; // { 1, 2, 3, 4, 5}
		x[i][IMAG] = 2;
	}
	// Plan the FFT and executr it
	fftw_plan plan = fftw_plan_dft_1d(n, x, y, FFTW_FORWARD, FFTW_ESTIMATE);
	fftw_execute(plan);
	fftw_destroy_plan(plan);
	fftw_cleanup();
	// Display the resuts
	cout <<"FFT = " << endl;
	for (int i=0; i<n; i++)
		if (y[i][IMAG] < 0)
			cout <<y[i][REAL] << " - " << abs(y[i][IMAG]) << "i" << endl;
		else
			cout <<y[i][REAL] << " + " << y[i][IMAG] << "i" << endl;
	return 0;
}
