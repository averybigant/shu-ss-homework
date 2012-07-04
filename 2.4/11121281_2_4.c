#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINEMAX 100

char *palindrome(char *str);


char *palindrome(char *str){
	int len, i;
	len = strlen(str) - 1;
	for (i = 0; i != len/2 + 1; i++)
		if(*(str+i) != *(str+len-1-i))return "No!";
	return "Yes!";
}

int main(void)
{
	int n, i;
	FILE *fp;
	char str[LINEMAX];
	fp = fopen("./data.txt", "r");
	fscanf(fp, "%d\n", &n);
	for (i = 0; i < n; i++) {
		fgets(str, LINEMAX, fp);
		printf("%s\n", palindrome(str));
	}
	fclose(fp);


	return 0;
}
