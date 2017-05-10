#ifndef FILTER_H
#define FILTER_H

#define PI 3.14159265

double **filter_create_gauss(int radius, double sigma);

void filter_print(double **filter, int radius);
void filter_free(double **filter, int radius);

#endif /*FILTER_H*/
