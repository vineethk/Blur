// source : https://raw.githubusercontent.com/Seo-Hyung/Gaussian-Smoothing-Filter/master/src.cpp
// removed opencv code
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv) {
	float tmp = 0.0, sigma, input, sum = 0.0, s, g = 0.0, **mask;
	int n, n_odd;

	// Load the image
	std::cout << "* Enter mask size n: ";
	std::cin >> input;
	n = input;
	std::cout << "* Enter sigma: ";
	std::cin >> input;
	sigma = input;
	s = 2.0*sigma*sigma;

	// Allocate mask memory
	mask = (float **)malloc(sizeof(float *) * n);
	for (int i = 0; i < n; i++)
		mask[i] = (float *)malloc(sizeof(float) * n);


	if (n % 2 == 1)
		n_odd = n - 1;
	else
		n_odd = n;

	// Create mask
	for (int x = (n_odd / 2)*(-1); x <= (n_odd / 2); x++) {
		for (int y = (n_odd / 2)*(-1); y <= (n_odd / 2); y++) {
			tmp = sqrt(x*x + y*y);
			mask[x + (n_odd / 2)][y + (n_odd / 2)] = (exp(-(tmp*tmp) / s)) / (3.1415*s);
			sum += mask[x + (n_odd / 2)][y + (n_odd / 2)];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			mask[i][j] /= sum;
	}

}
