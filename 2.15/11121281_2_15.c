#include <stdio.h>
#include <stdlib.h>

char *judge(unsigned int n){
	unsigned int i;
	unsigned int sum=0;
	for (i = 1; i <= n/2; i++) 
		if(n%i == 0)sum+=i;
	if(sum==n)return "YES";
	return "NO";
}

int main(void)
{
	FILE *fp;
	unsigned int n;
	fp = fopen("./data.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d\n", &n);
		printf("%s\n", judge(n));
	}
	return 0;
}
