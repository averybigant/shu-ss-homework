#include <stdio.h>
#include <math.h>
#define SCALE 1e-6

double factorial(unsigned long long int n){
	double result=1.0;
	int i;
	for (i = 2; i <= n; i++) 
		result *= i;
	return result;
}

double exp1(double x){
	unsigned long long int i;
	double sum=1.0;
	for (i = 1; i < 20; i++) 
		sum += pow(x, i) / factorial(i);
	return sum;
}

double exp2(double x){
	double this;
	unsigned long long int i=1;
	double sum=1.0;

	do{
		sum += this;
		this = pow(x, i) / factorial(i);
		i++;
	}while(this > SCALE);
		
	return sum;
}

int main(void)
{
	FILE *fp;
	double x;
	fp = fopen("./data.txt", "r");
	while( !feof(fp) ){
		fscanf(fp, "%lf\n", &x);
		printf("e1(%.3lf) = %.5lf\n", x, exp1(x) + 0.000005);
		printf("e2(%.3lf) = %.5lf\n\n", x, exp2(x) + 0.000005);
	}
	fclose(fp);
	return 0;
}

