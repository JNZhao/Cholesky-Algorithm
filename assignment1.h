#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MATSIZE 4

double ** choleskyDecomp(double ** A, int n, int i);
double ** mult(double ** L1,double ** L2, int n);
int identity(double ** A, int n);
void initMatrix(double ***mat,int n);
double **readMatrix(char * filename);
void freeMatrix(double ** matrix,int n);
void printMatrix(double ** A,int n);