#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

double gauss_2d(int x, int y, double sigma) {
	__pliny_fill__(USE_VARS, x, y, sigma);
	// double result = 1.0 / (2 * PI * sigma * sigma);
	// result *= exp(-(x*x+y*y)/(2 * sigma * sigma));
	// return result;
}

// compute the gaussian 2d function
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
