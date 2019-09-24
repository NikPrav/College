#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"


int  main(void) //main function begins
{
	
	FILE *fp,*fp1;
	fp = fopen("uni.dat","r");
	double* x;
	double n[1000000];
	double sum=0.0;	
	
	int i=0;
	
	while(fscanf(fp,"%lf",x)==1)
	{
		sum+=*x;
		n[i]=*x;
		++i;
	}
	
	double mean=sum/1e6;
	printf("%lf\n",mean);
	
	
	double sq=0;
	
		
	
	
	for(i=0;i<1e6;++i)
	{
		sq+=pow((n[i]-mean),2);
	}
	 
	double var=sq/1e6;
	printf("%lf\n",var);
	
	
	fp1 = fopen("uni.dat","r");
	while(fscanf(fp1,"%lf",x)==1)
	{
		
	}
	fclose(fp1);
return 0;
}
