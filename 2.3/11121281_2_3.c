#include <stdio.h>
#include <stdlib.h>
#define N 1000

int findmaxmin(int nums[], int n, int *max, int *maxi, int *min, int *mini);
int getdata(FILE *fp, int nums[]);

int findmaxmin(int nums[], int n, int *max, int *maxi, int *min, int *mini){
	int i, sum;
	*max = -3001;
	*min = 3001;
	if(n<3)return 0;
	for (i = 0; i < n - 2; i++) {
		sum = nums[i] + nums[i+1] + nums[i+2];
		if(sum>*max){
			*max = sum;
			*maxi = i + 1;
		}
		if(sum<*min){
			*min = sum;
			*mini = i + 1;
		}
	}
	return 1;
}

int getdata(FILE *fp, int nums[]){
	int i=0, n=0;
	do{
		fscanf(fp, "%d", &nums[i]);
		i++;
		n++;
	}while( ! (fgetc(fp) == '\n'));
	return n;
}

int main(void)
{
	int nlines, n, i;
	int max, maxi, min, mini;
	int nums[N];
	FILE *fp;

	fp = fopen("./data.txt", "r");
	fscanf(fp, "%d\n", &nlines);
	for (i = 0; i < nlines; i++) {
		n = getdata(fp, nums);
		printf("Case %d:\n", i+1);
		if(!findmaxmin(nums, n, &max, &maxi, &min, &mini))
			printf("No maximal and minimal!\n");
		else
			printf("maximum = %d, minimum = %d, MaxIndex = %d, MinIndex = %d\n",
				max, min, maxi, mini);
	}
	fclose(fp);

	return 0;
}
