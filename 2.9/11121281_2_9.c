#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int m, n, k, cas=1, smoke, nosmoke;
	int issmoke, allowchange;
	FILE *fp;
	fp = fopen("./data.txt", "r");
	while (!feof(fp)) {
		fscanf(fp, "%d %d\n", &m, &n);
		k = m - n;
		smoke = nosmoke = 0;
		printf("Case %d:\n", cas++);
		while (1) {
			fscanf(fp, "%d %d\n", &issmoke, &allowchange);
			allowchange = !allowchange;
			if(issmoke == -1)break;
			if(issmoke && smoke < n)printf("Smoking: %d\n", ++smoke);
			else if(((issmoke && allowchange) ||
					!issmoke) && nosmoke<k)printf("No Smoking: %d\n", ++nosmoke);
			else printf("Next flight leaves 6 hours\n");
		}
		printf("\n");
	}
	return 0;
}
