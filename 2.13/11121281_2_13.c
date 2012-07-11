#include <stdio.h>
#include <stdlib.h>

int issxh(int n){
	int sum=0;
	int t, sn;
	sn = n;
	do {
		t = n % 10;
		sum += t*t*t;
	} while (n /= 10);
	return sum == sn;
}

int main(void)
{
	FILE *fp;
	int n;
	fp = fopen("./data.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d\n", &n);
		if(issxh(n))printf("YES\n");
		else printf("NO\n");
	}
	fclose(fp);
	return 0;
}
