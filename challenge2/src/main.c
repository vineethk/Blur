#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filter.h"

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
