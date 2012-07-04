/*1.1.1*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void GetData(int *a, int n);
void Display(int *a, int n);
double GetAverage(int *a, int n);
int GetIndex1(int *a, int n, double x);
int GetIndex2(int *a, int n, double x);
int rand(void);



int main(void)
{
	int i, n;
	int *a;
	double x;

	while(1){
		printf("import n(0 for exit):");
		scanf("%d", &n);
		if(n == 0)break;
		printf("import x:");
		scanf("%lf", &x);
		a = malloc(sizeof(i) * n);
		GetData(a, n);
		Display(a, n);
		printf("\naverage:%lf\n", GetAverage(a, n));
		printf("index1:%d\n", GetIndex1(a, n, x));
		printf("index2:%d\n", GetIndex2(a, n, x));
		free(a);
	}
	return 0;
}


void GetData(int *a, int n){
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++,a++) 
		*a = rand() % 50 + 50;
}


	
void Display(int *a, int n){
	int i;
	for (i = 0; i < n; i++, a++) 
		printf("%2d ", *a);
}


double GetAverage(int *a, int n){
	int i, sum=0;
	for (i = 0; i < n; i++,a++) 
		sum += *a;
	return (double)sum/n;
}


int GetIndex1(int *a, int n, double x){
	int i, min=0;
	int *start;
	start = a;
	for (i = 0; i < n; i++,a++) 
		if(fabs(x - *(start+min)) > fabs(x - *a))min=i;
	return min;
}

int GetIndex2(int *a, int n, double x){
	int i, min;
	int *start;
	min = n - 1;
	start = a;
	a += n - 1;
	for (i = n-1; i >= 0; i--,a--) 
		if(fabs(x - *(start+min)) > fabs(x - *a))min=i;
	return min;
}

