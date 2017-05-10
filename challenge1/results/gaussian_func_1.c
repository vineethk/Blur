/* 
* File:   gaussBlur.cpp
* Author: Jared Sneesby
* Linux Compile: g++ -o <testBuild> -O3 GaussianBlur.cpp -std=c++11
* Cgywin Compile: g++ -o <testBuild> -O3 GaussianBlur.cpp -std=c++0x
* Run: ./<testBuild> <theImage.bmp> <Blur Radius: 1-9>
* changed from : gaussianFilterValue(int &i, int& j, int& kernelRadius,float& sigma) 
* --> gaussianFilterValue(int i, int j, int kernelRadius,float sigma) 
* Source : https://github.com/jsneesby/CSC415-GaussianBlur/blob/master/GaussianBlur.cpp
*/

#include <math.h>

/* Gaussian Mapping -- where the magic happens
/  --> maps pixel within kernel to a value between 0->1 
/  --> mapping uses e^-x to give outer pixels less significance
/  --> directly within loops to avoid activation record overhead
/  --> e^-x * e^-y = e^-(x+y)
*/
double gaussianFilterValue(int i, int j, int kernelRadius,float sigma){
	return exp( -((((i - kernelRadius)/(sigma))*((i - kernelRadius)/(sigma)) + (((j - kernelRadius)/(sigma))*((j - kernelRadius)/(sigma))))/2.0) );
}

