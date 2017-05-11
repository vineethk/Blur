// source : https://github.com/whdcumt/Gaussian_Blur/blob/master/code.c 
#include <math.h>


double Gauss(double sigma, double x)
{
	return exp(-(x * x) / (2.0 * sigma * sigma)) / (sigma * SQRT_2PI);
}

