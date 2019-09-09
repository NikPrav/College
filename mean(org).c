#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

double var(double E,char *str);

int main(void)
{
	double E=mean("uni.dat");
	printf("%lf\n",E);
	double var1=var(E,"uni.dat");
	printf("%lf\n",var1);
	
}

double var(double E,char *str) //Function for finding variance
{
	FILE *fp;
	fp=fopen(str,"r");
	
	double x=0;
	double sum=0.0,i=0;
	while(fscanf(fp,"%lf\n",&x)!=EOF)
	{
		sum=(x-E)*(x-E);
		++i;
	}
	
	double vari=(double)sum/i;
	return vari;
}
	
