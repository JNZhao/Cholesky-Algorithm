#include "assignment1.h"

void p1(void)
{
    double **matrix;
    initMatrix(&matrix,MATSIZE);
    printMatrix(matrix,MATSIZE);
    freeMatrix(matrix,MATSIZE);
}

void p2(void)
{
    double ** matrix=readMatrix("matrix.txt");
    printMatrix(matrix,MATSIZE);
    freeMatrix(matrix,MATSIZE);
}

void p3(void)
{
    double ** matrix=readMatrix("matrix.txt");
    double ** multMatrix = mult(matrix, matrix, MATSIZE);
    printMatrix(multMatrix,MATSIZE);
    freeMatrix(multMatrix,MATSIZE);
}

void p4(void)
{
    double ** matrix=readMatrix("matrix.txt");
    printf("Is this an identity matrix? %d\n",identity(matrix,MATSIZE));
    freeMatrix(matrix,MATSIZE);
}

void p5(void)
{
    char dataFileMat1[]="matrix.txt";
    double ** matrix=readMatrix(dataFileMat1);
    double ** L=choleskyDecomp(matrix, MATSIZE,0);
    printf("The cholesky decomposition of the matrix is: \n");
    printMatrix(L,MATSIZE);
    freeMatrix(L,MATSIZE);
}

int main( int argc, char *argv[] )
{
    if( argc < 2 || argc > 2)
   	{
        printf("Expecting one argument. Please try again\n");
   	}
    else if(argc==2)
    {
        if(atoi(argv[1])==1)
        {
            p1();
        }
        else if(atoi(argv[1])==2)
        {
            p2();
        }
        else if(atoi(argv[1])==3)
        {
            p3();
        }
        else if(atoi(argv[1])==4)
        {
            p4();
        }
        else if(atoi(argv[1])==5)
        {
            p5();
        }
        else
        {
            printf("Incorrect argument supplied.\n");
        }
    }
}

