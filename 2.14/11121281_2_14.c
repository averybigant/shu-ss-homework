#include <stdio.h>
#include <stdlib.h>
#define CH *str
#define MAXSTR 144

void calcstr(char *str){
	int total, num, space, alpha;
	total = num = space = alpha = 0;
	while (CH != '\0' && CH != '\n') {
		if(CH == ' ')space++;
		if( (CH >= 'a' && CH <= 'z') || (CH >= 'A' && CH <= 'Z'))
			alpha++;
		if(CH <= '9' && CH >= '0')num++;
		total++;
		str++;
	}
	printf("%d %d %d %d\n", alpha, num, space, total - 
			(alpha + num + space));
}

int main(void)
{
	FILE *fp;
	char str[MAXSTR];
	char headchar;

	fp = fopen("./data.txt", "r");

	fgets(str, MAXSTR, fp);
	calcstr(str);
	headchar = fgetc(fp);
	while (!feof(fp)) {
		fgets(str+1, MAXSTR, fp);
		str[0] = headchar;
		calcstr(str);
		headchar = fgetc(fp);
	}
	fclose(fp);
	return 0;
}
