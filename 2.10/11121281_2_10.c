#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100

int readarr(int arr[][MAXLEN], FILE *fp){
	int n, i, j;
	fscanf(fp, "%d\n", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) 
			fscanf(fp, "%d", &(arr[i][j]));
		fgetc(fp);
	}
	fgetc(fp);
	return n;
}

int isSaddlePoint(int arr[][MAXLEN], int ii, int jj, int n){
	int i, j;
	int this;
	this = arr[ii][jj];
	for (j = 0; j < n; j++) 
		if(arr[ii][j] > this)return 0;
	for (i = 0; i < n; i++) 
		if(arr[i][jj] < this)return 0;
	return 1;
}

int haveSaddlePoint(int arr[][MAXLEN], int n){
	int i, j;
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			if(isSaddlePoint(arr, i, j, n))return 1;
	return 0;
}

int main(void)
{
	int arr[MAXLEN][MAXLEN];
	FILE *fp;
	int t, n, i;
	fp = fopen("./data.txt", "r");
	fscanf(fp, "%d\n", &t);
	for (i = 0; i < t; i++) {
		n = readarr(arr, fp);
		if(haveSaddlePoint(arr, n))printf("YES\n");
		else printf("NO\n");
	}
	fclose(fp);
	return 0;
}
