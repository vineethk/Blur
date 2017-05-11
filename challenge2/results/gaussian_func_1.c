/* 
* File:   gaussBlur.cpp
* Author: Jared Sneesby
* Linux Compile: g++ -o <testBuild> -O3 GaussianBlur.cpp -std=c++11
* Cgywin Compile: g++ -o <testBuild> -O3 GaussianBlur.cpp -std=c++0x
* Run: ./<testBuild> <theImage.bmp> <Blur Radius: 1-9>
* src : https://raw.githubusercontent.com/jsneesby/CSC415-GaussianBlur/master/GaussianBlur.cpp
*/

#include <math.h>

/* Gaussian Blur 
/  --> Main algorithm implimentation
/
/ @params --> image(bitmap_image): reference to image in main method
/         --> kernelRadius(int): desired radius of kernel  
/
/ @vars   --> image: reference to full sized bitmap image /////////////////////////////////////////////////-------------------------------> fill in all major params
/         --> kernelRadius: integer
/         --> kernelRadius: integer
/         --> kernelRadius: integer
/         --> kernelRadius: integer
/         --> kernelRadius: integer
/         --> kernelRadius: integer
*/
void gaussinBlurBMP(int kernelRadius){
	// need to do calculations off of different image, not original (otherwise everything is a bit off)
	//bitmap_image theImage = image;
	double gaussianFilterValue(int i, int j, int kernelRadius,float sigma);

	int kernelSize = 2*kernelRadius+1; // width and height of kernel, assumes square kernel
	float sigma = kernelRadius/2.0; // calculate sigma
	double sum, redSum, greenSum, blueSum;  // sum of values within each kernel
	double kernel2d[kernelSize][kernelSize];
	
	sum=0;
	// make the 2d kernel to hold surrounding pixel weights --> done outside loop because it will not change
	for (int i = 0; i < kernelSize; i++){
		for (int j = 0; j < kernelSize; j++){
			kernel2d[i][j] = gaussianFilterValue(i, j, kernelRadius, sigma);

			// adds this kernel value to kernal sum
			sum += kernel2d[i][j];
		}
	}
	// normalize (map all values to add up to 1 using their ratio relative to the sum)
	for (int i = 0; i < kernelSize; i++){
		for (int j = 0; j < kernelSize; j++){
			kernel2d[i][j] /= sum;
		}
	}
}
