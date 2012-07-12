#include <stdio.h>
#include <stdlib.h>

double add(double a, double b){
	return a + b;
}

double sub(double a, double b){
	return a - b;
}

double mul(double a, double b){
	return a * b;
}

double divi(double a, double b){
	return a / b;
}
static double (*op[4])(double, double) = {add, sub, mul, divi};
static char sop[4] = {'+', '-', '*', '/'};

//================================

void findresult(double a, double b, double c, double d){
	int i, j, k;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			for (k = 0; k < 4; k++) {
				if(op[k](op[j](op[i](a,b), c),d)==24){
					printf("[(%.0lf %c %.0lf) %c %.0lf] %c %.0lf" ,
							a, sop[i], b, sop[j], c, sop[k], d);
					printf(" = 24\n");return;
				}
				if(op[k](op[i](a, op[j](b, c)), d)==24){
					printf("[%.0lf %c (%.0lf %c %.0lf)] %c %.0lf" ,
							a, sop[i], b, sop[j], c, sop[k], d);
					printf(" = 24\n");return;
				}
				if(op[j](op[i](a,b), op[k](c,d))==24){
					printf("(%.0lf %c %.0lf) %c (%.0lf %c %.0lf)" ,
							a, sop[i], b, sop[j], c, sop[k], d);
					printf(" = 24\n");return;
				}
				if(op[i](a, op[k](op[j](b, c), d))==24){
					printf("%.0lf %c [(%.0lf %c %.0lf) %c %.0lf]" ,
							a, sop[i], b, sop[j], c, sop[k], d);
					printf(" = 24\n");return;
				}
				if(op[i](a, op[j](b, op[k](c, d)))==24){
					printf("%.0lf %c [%.0lf %c (%.0lf %c %.0lf)]" ,
							a, sop[i], b, sop[j], c, sop[k], d);
					printf(" = 24\n");return;
				}
			}
		}
	}
	printf("Impossible!\n");
}

int main(void)
{
	int i=1;
	double a, b, c, d;
	FILE *fp;
	fp = fopen("./data.txt", "r");
	while (!feof(fp)) {
		printf("Case %d: ", i);
		fscanf(fp, "%lf %lf %lf %lf\n", &a,&b,&c,&d);
		findresult(a, b, c, d);
		i++;
	}
	fclose(fp);
	return 0;
}

