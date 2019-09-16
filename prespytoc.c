#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

double **idmat(int k);
double **scalmult(double **A,int m,int k,double scal);
int matequal(double **A,double **B, int m, int k);

int main()
{
double **A,**B,*r,l=0;
double **I;
int *n;
	int k=0;
	r=&l;
	n=&k;
	printf("Enter no.of rows\n");
	scanf("%d",n);
	
	A=createMat(*n,*n);
	B=createMat(*n,*n);
	I=idmat(*n);
		
	printf("Enter Elements\n");
	for(int i=0;i<*n;++i)
	{
		for(int j=0;j<*n;++j)
		{
			
			scanf("%lf",r);
			A[i][j]=*r;
		}
	}
	double **a3=scalmult(A,*n,*n,3);
	B=linalg_sub(I,a3,*n,*n);
	B=scalmult(B,*n,*n,0.5);
	
	
	
	 if(matequal(linalg_sub(scalmult(A,*n,*n,3),scalmult(B,*n,*n,-10),*n,*n),scalmult(I,*n,*n,2),*n,*n))
	 printf("\n (i) is true\n");
	 else
	 printf("\n (i) is false\n");	 
	 
	 if(matequal(linalg_sub(scalmult(A,*n,*n,10),scalmult(B,*n,*n,-5),*n,*n),scalmult(I,*n,*n,3),*n,*n))
	 printf("\n (ii) is true\n");
	 else
	 printf("\n (ii) is false\n");
	 
	 if(matequal(linalg_sub(scalmult(A,*n,*n,2),scalmult(B,*n,*n,-1),*n,*n),scalmult(I,*n,*n,3),*n,*n))
	 printf("\n (iii) is true\n");
	 else
	 printf("\n (iii) is false\n");
	 
	 if(matequal(linalg_sub(scalmult(A,*n,*n,3),scalmult(B,*n,*n,-6),*n,*n),scalmult(I,*n,*n,2),*n,*n))
	 printf("\n (iv) is true\n");
	 else
	 printf("\n (iv) is false\n");
	 
	 
	
	 free(A);
	 free(B);
	 free(I);
	 return 0;
	  
	 
	}

double **idmat(int n)
{
	double **a;
	a=createMat(n,n);
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i==j)
			a[i][j]=1;
			else
			a[i][j]=0;
		}
	}
	return a;
}

double **scalmult(double **A,int m,int n,double scal)
{
	double **a;
	a=createMat(n,n);
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			a[i][j]=scal*(A[i][j]);
			
		}
	}
	return a;
	
}

int matequal(double **A,double **B, int m, int n)
{
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(A[i][j]!=B[i][j])
			return 0;
			
		}
	}
	return 1;
}

