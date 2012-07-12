#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#define SCALE 1e-8
#define HFSQRT3 0.866025403784

double _Complex interation(double _Complex z){
	double _Complex last;
	last = z;
	do {
		last = z;
		z = z-(cpow(z, 3)-1)/(3 * cpow(z, 2));
	} while (cabs(last-z) > SCALE);
	return z;
}

unsigned int checkans(double _Complex z){
	double _Complex w[3] = {1, - 0.5 + HFSQRT3*I,
		- 0.5 - HFSQRT3*I};
	int i;
	for (i = 0; i < 3; i++) 
		if(cabs(w[i]-z) < SCALE)return i;
}

int main(void)
{
	double _Complex z;
	FILE *fp;
	double real, img;
	int i=1;

	fp = fopen("./data.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%lf %lf\n", &real, &img);
		z = real + img * I;
		printf("Case %d: %u\n", i++, checkans(interation(z)));
	}

	fclose(fp);
	return 0;
}
