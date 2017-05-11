// Moved the constructor initialization for variables to function
// https://github.com/mohab1989/ImageFiltering/blob/master/Image%20Filtering%20Solution/ProFilter/Kernel.cpp
#include <math.h>

void GaussianKernel(unsigned long KernelLength, float sigma)
{
	unsigned long mKernelLength = KernelLength;
        int padding = (int)(KernelLength/2);
	float sum=0;
	float KernelMatrix[mKernelLength][mKernelLength];
	for( int i=0 ,x=-padding ; i < mKernelLength,x<=padding ; i++,x++ )
	{
		for(int j = 0 ,y=-padding;  j <  mKernelLength ,y<=padding; j++,y++)
		{
			//2D gaussian formula
			KernelMatrix[i][j] = (1/(2*(22/7)*pow(sigma,2)))*exp((-1*((x*x)+(y*y)))/(2*sigma*sigma));
			sum+=KernelMatrix[i][j];
		}
	}
	for( int i = 0 ; i < mKernelLength ; i++ )
	{
		for(int j = 0 ;  j <  mKernelLength ; j++)
		{
			KernelMatrix[i][j] = (KernelMatrix[i][j])/sum;
		}
	}
}
