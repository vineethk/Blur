#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pliny_fill.h"

#define PI 3.14159265

double gauss_2d(int x, int y, double sigma) {
	double result = 1.0 / (2 * PI * sigma * sigma);
	result *= exp(-(x*x+y*y)/(2 * sigma * sigma));
	return result;
}

double **filter_create_gauss(int radius, double sigma) {
	//Used for iterations
	int i, j;

	//The matrix width and height
	int dim = 2*radius+1;

	//Alocate mem for the matrix
	double **filter = (double**) malloc(dim * sizeof(double*));

	for(i = 0; i < dim; i++)
		filter[i] = (double*) malloc(dim * sizeof(double));

	//Calculate
	double sum = 0.0;
  /*
	for(i = -radius; i <= radius; i++)
		for(j = -radius; j <= radius; j++) {
			filter[i+radius][j+radius] = gauss_2d(j, i, sigma);
			sum += filter[i+radius][j+radius];
		}
  */
  __pliny_fill__(WRITE_TO, sum,
                 READ_FROM, filter, i, j,
                 USE_VARS, i, j, radius, sigma, sum, filter);

	//Correct so that the sum of all elements ~= 1
	for(i = 0; i < 2*radius+1; i++)
		for(j = 0; j < 2*radius+1; j++)
			filter[i][j] /= sum;

	return filter;
}

void filter_print(double **filter, int radius) {
	int dim = 2*radius+1, i, j;
	for(i = 0; i < dim; i++) {
		for(j = 0; j < dim; j++) 
			printf("%lf ", filter[i][j]);
		printf("\n");
	}
}

void filter_free(double **filter, int radius) {
	//Free matrix
	int dim=2*radius+1, i;
	for(i = 0; i < dim; i++)
		free(filter[i]);
	free(filter);
}

int main(int argc, char *argv[]) {
	int radius;
	double sigma;
  double **filter;

	//Arguments: argv[0]="path", argv[1]="radius" argv[2]="sigma"
	if(argc == 3) {	//If enought arguments given take the info from the them
		//Convert radius
		radius = atoi(argv[1]);
	
		//Convert sigma
		sigma = atof(argv[2]);
	} else { //Read info from keyboard
		//Read radius
		printf("Radius: ");
		scanf("%d", &radius);

		//Read sigma
		printf("Sigma: ");
		scanf("%lf", &sigma);
	}

	//Create filter
	filter = filter_create_gauss(radius, sigma);

  filter_print(filter, radius);

	//Free memory
	filter_free(filter, radius);

	return 0;
}
