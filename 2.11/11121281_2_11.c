#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100
#define FMTS "%3d "

void createarr(int arr[][MAXLEN], int n){
	int num=0, i;
	int flag = 1;
	int ii, jj;
	ii = 0;
	jj = n - 1;

	for (i = 0; i < n; i++) 
		arr[0][i] = ++num;

	while (n--) {
		for (i = n; i > 0; i--) {
			ii += flag;
			arr[ii][jj] = ++num;
		}
		for (i = n; i > 0; i--) {
			jj -= flag;
			arr[ii][jj] = ++num;
		}
		flag *= -1;
	}
}

void printarr(int arr[][MAXLEN], int n){
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) 
			printf(FMTS, arr[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int arr[MAXLEN][MAXLEN];
	FILE *fp;
	int n;

	fp = fopen("./data.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d\n", &n);
		createarr(arr, n);
		printarr(arr, n);
		printf("\n");
	}
	fclose(fp);
	return 0;
}
