#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 1000

void createarray(long long int arr[], int n){
	int i;
	arr[0] = 25;
	if(n==1)return;
	arr[1] = -25;
	if(n==2)return;

	for (i = 2; i < n; i++) 
		arr[i] = (arr[i-1]*4627 + arr[i-2]*3581) / 100%100 - 50;
}

void sort(long long int arr[], int n){
	long long int temp;
	int minindex;
	int i, j;

	for (i = 0; i < n; i++) {
		minindex = i;
		for (j = i+1; j < n; j++) 
			if(arr[j] < arr[minindex])minindex = j;
		temp = arr[i];
		arr[i] = arr[minindex];
		arr[minindex] = temp;
	}
}

void show(long long int arr[], int n){
	int i;
	for (i = 0; i < n - 1; i++) 
		printf("%lld ", arr[i]);
	printf("%lld", arr[i]);//尾部无多余空格
	printf("\n");
}

int main(void)
{
	FILE *fp;
	int n;
	long long int arr[MAXLEN];

	fp = fopen("./data.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d\n", &n);
		createarray(arr, n);
		sort(arr, n);
		show(arr, n);
	}
	fclose(fp);
	return 0;
}

