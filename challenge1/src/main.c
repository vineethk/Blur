#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filter.h"

int main(int argc, char *argv[]) {
	int radius, x, y;
	double sigma;
  double **filter;

	//Arguments: argv[0]="path", argv[1]="x", argv[2]="y", argv[3]="sigma"
	if(argc == 4) {	//If enought arguments given take the info from the them
		//Convert X
		x = atoi(argv[1]);
	
		//Convert Y
		y = atoi(argv[2]);
	
		//Convert sigma
		sigma = atof(argv[3]);
	} else { //Read info from keyboard
		//Read X
		printf("X: ");
		scanf("%d", &x);

		//Read Y
		printf("Y: ");
		scanf("%d", &y);

		//Read sigma
		printf("Sigma: ");
		scanf("%lf", &sigma);
	}

	//Generate gauss_2d val for (x,y)
  double result;
  result = gauss_2d(x, y, sigma);
	printf("%lf\n", result);

	return 0;
}
