#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long sum, num;
	unsigned int i=1, j=0;
	FILE *fp;
	fp = fopen("./data.txt", "r");
	 do{
		sum = j = 0;
		do {
			fscanf(fp, "%ld", &num);
			sum += num;
			j++;
		} while (fgetc(fp)!='\n' && !feof(fp));
		if(feof(fp))break;
		printf("Case %u: %u, %ld\n", i++, j, sum);
	}while (!feof(fp));
	fclose(fp);
	return 0;
}
