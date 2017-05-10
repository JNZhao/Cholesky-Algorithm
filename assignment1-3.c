#include "assignment1.h"
double ** choleskyDecomp(double ** A, int n, int i)
{
    int j,k;
    double multres=0;
    double a1[1][n-1-i];
    double a2[n-1-i][1];
    double ** L;
    double **m;

    for(j=0;j<1;j++)
    {
        for(k=0;k<(n-i-1);k++)
        {
            a1[j][k]=A[j+i][k+1+i];

        }
    }
    for(j=0;j<(n-i-1);j++)
    {
        for(k=0;k<1;k++){
        a2[j][k]=A[j+i+1][k+i];
        }
    }


initMatrix(&m,n);
for(j=0;j<n;j++)
{
    for (k=0;k<n;k++)
    {
        if (j<(i+1)||k<(i+1))
        {
            if (j!=k)
            {
                m[j][k]=0;
            }
            else
            {
                m[j][k]=1;
            }
        }
        else
        {
            m[j][k]=A[j][k]-(a1[0][k-1-i]*a2[j-1-i][0])/(A[i][i]);
        }

}

}
initMatrix(&L,n);
for (j=0;j<n;j++)
{
    for (k=0;k<n;k++)
    {

        if(j<i||k<i)
        {
            if(j==k)
            {
                L[j][k]=1;
            }
            else
            {
                L[j][k]=0;
            }
        }
        else if(j==i&&k==i)
        {
            L[j][k]=sqrt(A[i][i]);

        }
        else if(j==i&&k!=i)
        {
            L[j][k]=0;
        }
        else if (k==i && j!=i)
        {

            L[j][k]=A[j][k]/(sqrt(A[i][i]));

        }
        else{
            if (j==k)
            {
                L[j][k]=1;
            }
        else
        {
            L[j][k]=0;
        }
        }

}
}
if (identity(m,n)==1)
{
    freeMatrix(A,n);
    freeMatrix(m,n);
    return L;
}
else{
    freeMatrix(A,n);
    return mult (L,choleskyDecomp(m,n,i+1),n);
}
}

double ** mult(double ** L1,double ** L2, int n)
{
    int i,j,k;
    double ** L3;
    initMatrix(&L3,n);
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {


         scanf("%d",(*(L1+i)+j));

        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {

            scanf("%d",(*(L2+i)+j));

        }
    }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                *(*(L3+i)+j)=0;

                for(k=0;k<n;k++)
                {
                    *(*(L3+i)+j)+=(*(*(L1+i)+k)**(*(L2+k)+j));

                }
            }
        }
       if(L1==L2)
       {
           freeMatrix(L1,n);
       }
       else{
        freeMatrix(L2,n);
        freeMatrix(L1,n);
       }
       return L3;
            }








int identity(double ** A, int n)
{
    int i,j;
    int result=1;

    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (A[i][j]!=1&&A[j][i]!=0)
            {
               result=0;
               break;
            }
    }


    }
    return result;
}


void initMatrix(double ***mat,int n)
{
    int i,j;
    *mat=(double**)malloc(MATSIZE*sizeof(double *));

    for(i=0;i<MATSIZE;i++)
    {
        (*mat)[i]=(double*)malloc(MATSIZE*sizeof(double));
    }
    for (i=0;i<MATSIZE;i++)
    {
        for (j=0;j<MATSIZE;j++)
        {
            (*mat)[i][j]=0;
        }

    }
    }



double **readMatrix(char * filename)
{
    int a,b;

    FILE *fp=fopen(filename,"r");
    double **mat=(double**)malloc(sizeof(double*)*(unsigned long)MATSIZE);
    initMatrix(&mat,MATSIZE);
    for( a=0;a<MATSIZE;a++)
    {
        mat[a]=(double*)malloc(sizeof(double)*(unsigned long)MATSIZE);
        for (b=0;b<MATSIZE;b++)
        {
            fscanf(fp,"%lf",&(mat[a][b]));
        }

    }
return mat;
}


void freeMatrix(double ** matrix, int n)
{


         int i;
         for (i=0;i<n;i++)
         {
             free (matrix[i]);
         }

         free (matrix);

}

void printMatrix(double ** A, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             printf("lf",A[i][j]);
        }
         printf("\n");
    }

}
























