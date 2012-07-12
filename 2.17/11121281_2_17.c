#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SCALE 1e-7

int LogisticT(double lambda){
	int i;
	double this, last = 0.5;
	for (i = 0; i < 10000; i++) 
		last = lambda * last * (1 - last);
	this = last;
	for (i = 1; i < 1024; i++) {
		last = lambda * last * (1 - last);
		if(fabs(last - this) < SCALE)return i;
	}
	return -1;
}

int main(void)
{
	double lambda;
	unsigned int i=1;
	FILE *fp;
	fp = fopen("./data.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%lf\n", &lambda);
		printf("Case %u: %g, %d\n", i++, lambda, LogisticT(lambda));
	}
	return 0;
}

