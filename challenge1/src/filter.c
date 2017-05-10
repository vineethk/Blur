#include "filter.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


double gauss_2d(int x, int y, double sigma) {
	double result = 1.0 / (2 * PI * sigma * sigma);
	result *= exp(-(x*x+y*y)/(2 * sigma * sigma));
	return result;
}
