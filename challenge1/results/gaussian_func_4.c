// Source https://github.com/itatriev/gaussian3x3/blob/master/gaussian.cpp
// Moved constuctor source into the function
#include <math.h>

void produce2dGaussianKernel(int kernelRadius, double sigma, double mean)
{
    double sum;
    double kernel[kernelRadius][kernelRadius];

    // Fill the values into the kernel
    for(int x = 0; x < kernelRadius; x++)
        for(int y = 0; y < kernelRadius; y++) {
            kernel[x][y] = exp( -0.5 * (pow((x-mean)/sigma, 2.0) + pow((y-mean)/sigma,2.0)) );

            sum += kernel[x][y];
        }

    for(int x = 0; x < kernelRadius; x++)
        for(int y = 0; y < kernelRadius; y++)
            kernel[x][y] /= sum;
}
