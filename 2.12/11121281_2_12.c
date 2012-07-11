#include <stdio.h>
#include <stdlib.h>
#define FAC3 6

unsigned long long int factorial(unsigned long long int n){
	unsigned long long int i;
	unsigned long long int mut=1;
	for (i = 1; i < n+1; i++) 
		mut *= i;
	return mut;
}

unsigned long long int calctriangles(unsigned long long int points){
	if(points < 3)return 0;
	return factorial(points) / FAC3 / factorial(points - 3);
}

int main(void)
{
	FILE *fp;
	unsigned long long int points;
	fp = fopen("./data.txt", "r");
	while (!feof(fp)) {
		fscanf(fp,  "%llu ", &points);
		printf("%llu\n", calctriangles(points));
	}
	fclose(fp);
	return 0;
}
