#include <stdio.h>
#include <string.h>
#define MAXLEN 100

int main(void)
{
	int n, i, j;
	char str[MAXLEN];
	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		gets(str);
		for (j = strlen(str)-1; j >= 0; j--) 
			putchar(str[j]);
		putchar('\n');
	}
	return 0;
}
