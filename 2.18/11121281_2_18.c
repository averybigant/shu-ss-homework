#include <stdio.h>
#include <stdlib.h>

int times(int num){
	int i=0;
	if(num<=0)return -1;
	while (num!=1) {
		if (num % 2 == 0) 
			num /= 2;
		else
			num = 3 * num + 1;
		i++;
	}
	return i;
}

int main(void)
{
	FILE *fp;
	int i=1;
	int num;
	fp = fopen("./data.txt", "r");
	 do{
		fscanf(fp, "%d", &num);
		printf("Case %d: %d, %d\n", i++, num, times(num));
	}while (fgetc(fp)!='\n');
	fclose(fp);
	return 0;
}
