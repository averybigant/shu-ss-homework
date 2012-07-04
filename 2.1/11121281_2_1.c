#include <stdio.h>
#include <stdlib.h>

int getGCD(int a, int b);
int getLCM(int a, int b, int);

int getGCD(int a, int b){
	int r, t;
	r = b;
	while (r!=0) {
		t = r;
		r = a % r;
		a = t;
	}
	return a;
}

int getLCM(int a, int b, int gcd){
	return a * b / gcd;
}

int main(void)
{
	int i, a, b, gcd;
	FILE *fp;
	fp = fopen("data.txt", "r");
	for(i=1 ; !feof(fp) ; i++){
		fscanf(fp, "%d %d\n", &a, &b);
		printf("Case %d:\n", i);
		if(a==0 && b==0){
			printf("no GCD\nno LCM\n");
			continue;
		}
		gcd = getGCD(a, b);
		printf("GCD(%d,%d) = %d\n", a, b, gcd);
		printf("LCM(%d,%d) = %d\n", a, b, getLCM(a, b, gcd));
	}
	return 0;
}
