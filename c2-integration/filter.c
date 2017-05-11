#include "filter.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


FILTER *filter_create_avg(int radius) {
	//Allocate mem for the structure
	FILTER *filter = (FILTER*) malloc(sizeof(FILTER));
	filter->radius = radius;
	filter->type = FILTER_AVG;

	//Used for iterations
	int i, j;

	//The matrix width and height
	int dim = 2*radius+1;

	//Alocate mem for the matrix
	filter->matrix = (double**) malloc(dim * sizeof(double*));
	for(i = 0; i < dim; i++)
		filter->matrix[i] = (double*) malloc(dim * sizeof(double));

	//The value that every entry in the matrix will contain
	double avg = 1.0 / (dim * dim);

	//Set the values
	for(i = 0; i < dim; i++)
		for(j = 0; j < dim; j++)
			filter->matrix[i][j] = avg;

	return filter;	
}

double gauss_2d(int x, int y, double sigma) {
	double result = 1.0 / (2 * PI * sigma * sigma);
	result *= exp(-(x*x+y*y)/(2 * sigma * sigma));
	return result;
}

double **filter_create_gauss_matrix(int radius, double sigma) {
  // Used for iterations
  int i, j;

  // The matrix width and height
  int dim = 2 * radius + 1;

  // Alocate mem for the matrix
  double **filter = (double **)malloc(dim * sizeof(double *));

  for (i = 0; i < dim; i++)
    filter[i] = (double *)malloc(dim * sizeof(double));

  // Calculate
  double sum = 0.0;
  /*
        for(i = -radius; i <= radius; i++)
                for(j = -radius; j <= radius; j++) {
                        filter[i+radius][j+radius] = gauss_2d(j, i, sigma);
                        sum += filter[i+radius][j+radius];
                }
  */
  for( int i=0 ,x=-radius ; i < i,x<=radius ; i++,x++ )
	{
		for(int j = 0 ,y=-radius;  j <  i ,y<=radius; j++,y++)
		{
			//2D gaussian formula
			filter[i][j] = (1/(2*(22/7)*pow(sigma,2)))*exp((-1*((x*x)+(y*y)))/(2*sigma*sigma));
			sum+=filter[i][j];
		}
	}

  // Correct so that the sum of all elements ~= 1
  for (i = 0; i < 2 * radius + 1; i++)
    for (j = 0; j < 2 * radius + 1; j++)
      filter[i][j] /= sum;

  return filter;
}

FILTER *filter_create_gauss(int radius, double sigma) {
	//Allocate mem for the structure
	FILTER *filter = (FILTER*) malloc(sizeof(FILTER));
	filter->radius = radius;
	filter->type = FILTER_GAUSS;
  filter->matrix = filter_create_gauss_matrix(radius, sigma);
	return filter;
}

void filter_print(FILTER *filter) {
	int dim = 2*filter->radius+1, i, j;

	for(i = 0; i < dim; i++) {
		for(j = 0; j < dim; j++) 
			printf("%lf ", filter->matrix[i][j]);
		printf("\n");
	}
}

void filter_free(FILTER *filter) {
	//Free matrix
	int dim=2*filter->radius+1, i;
	for(i = 0; i < dim; i++)
		free(filter->matrix[i]);
	free(filter->matrix);

	//Free filter
	free(filter);
}
