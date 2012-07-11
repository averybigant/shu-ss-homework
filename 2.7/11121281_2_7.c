#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 100

void swap(char **s1, char **s2){
	char *temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}


int main(void)
{
	int n, i;
	char s1[MAXLEN], s2[MAXLEN];
	char *str1, *str2;
	FILE *fp;
	fp = fopen("./data.txt", "r");
	fscanf(fp, "%d\n", &n);
	for (i = 0; i < n; i++) {
		fgets(s1, MAXLEN, fp);
		fgets(s2, MAXLEN, fp);
		fgetc(fp);
		str1 = s1;
		str2 = s2;
		swap(&str1, &str2);
		printf("Case %d:\n", i+1);
		printf("%s", str1);
		printf("%s", str2);
	}
	return 0;
}
