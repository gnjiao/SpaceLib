/*
    TEST-LIN: Sample program which reads and solves a linear system
	      whose matrix of coefficient and whose right-hand side vector
	      are memorized in file INP.DAT
	      A*x=b
*/

#include <stdio.h>
#include <stdlib.h>
#include "SPACELIB.H"
#include "LINEAR.H"
#define Nmax 6
#define Mmax 7
int main(void)
{
	real H[Nmax][Mmax+1], A[Nmax][Mmax], x[Mmax], b[Nmax];
	int ivet[Mmax],vpr[1];
	int i,j,irank,n,m;
	real arm;
	real t;
	FILE *f;
	vpr[0]=-1;
	/* read matrix of coefficients and right-hand side vector from file */
	f=fopen("INP.DAT","r");
	if(f==NULL)
	{
		printf("Error on input file\a");
		exit(1);
	}
	fscanf(f,"%d %d",&n,&m);  /* read dimension of matrix */
	if(n>Nmax || m>Mmax)
	{
		printf("ERROR: matrix too big");
		exit(1);
	}
	for(i=0;i<n;i++)          /* read matrix and vector */
	{
		for(j=0;j<m;j++)
		{
			fscanf(f,SCNr,&t);
			A[i][j]=(real)t;
		}
		fscanf(f,SCNr,&t);
		b[i]=(real)t;
	}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)                 /* copy matrix of coefficients */
			H[i][j]=A[i][j];
	for(j=0;j<n;j++)                         /* copy right-hand side vector */
		H[j][m]=b[j];
	printf("\n Matrix and right-hand side vector\n\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m+1;j++)
			printf("%7.3f ",H[i][j]);
		printf("\n");
	}
	printf("\n");

	linear(M H,Nmax,Mmax+1,n,m,1,ivet,&irank,&arm,vpr); /* solve system */
	if(n==m && irank==n)
	{
		printf("The solution is\n");
		for(i=0;i<n;i++)                  /* reorder solution */
			x[ivet[i]]=H[i][n];
		for(i=0;i<n;i++)                  /* output results */
			printf(PRIr" ",x[i]);
	}
	else
	{
		if(n!=m)
			printf("The number of rows and columns are different\n");
		printf("The rank of the matrix is %d\n\n",irank);
		for(i=0;i<m;i++)
			printf("%7d ",ivet[i]);
		printf("\n\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<m+1;j++)
				printf("%7.3f ",H[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	exit(0);
}
