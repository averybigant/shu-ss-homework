/*1.1.2*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 60

typedef struct{
	char sid[10];
	char sname[20];
	double stall;
}STUDENT;

char *fgetline(FILE *fp, char *str, int n, char delim);
int getRecs(char *filename,STUDENT *s, int n);
void Sort(STUDENT *s, int n);
void Display(STUDENT *s, int n);


char *fgetline(FILE *fp, char *str, int n, char delim){
	int i;
	if( feof(fp) )return NULL;
	for (i = 0; i < n; i++) {
		fgets(str, n, fp);

		while (*str) {
			if(*str == delim){
				*str = '\0';
				break;
			}
		}
	}
	return *str;
}


int getRecs(char *filename,STUDENT *s, int n){
	char str[100];
	char tempstr[100];
	char *indexname, *indextall;
	int i=0;
	FILE *fp;
	fp = fopen(filename, "r");
	if(fp == NULL)exit(1);
	while ( ! fgetline(fp, str, 100, '\n') ) {
		strcpy(tempstr, str);
		indexname = strchr(tempstr, '\t');
		*indexname = '\0';
		strcpy((*s).sid, tempstr);

		indextall = strchr(indexname + 1, '\t');
		*indextall = '\0';
		strcpy((*s).sname, indexname + 1);

		(*s).stall = atof(indextall + 1);
		s += 1;
		i++;
		if(i>n)break;
	}
	return i>n?n:i;
		
	}


void Sort(STUDENT *s, int n){
	int i, k, indexmax;
	STUDENT temp, s1, s2;
	for (i = n; i >= 0; i--) {
		indexmax = 0;
		for (k = i; k >= 0; k--) {
			s1 = *(s+indexmax);
			s2 = *(s+k);
			if(s1.stall < s2.stall)indexmax=k;
		}
		temp = *(s+k);
		*(s+k) = *(s+indexmax);
		*(s+indexmax) = temp;
		
	}
}


void Display(STUDENT *s, int n){
	int i;
	STUDENT currents;
	for (i = 0; i < n; i++) {
		currents = *(s + i);
		printf("%s\t%s\t%lf\n", currents.sid, currents.sname, currents.stall);
	}
}

int main(void)
{
	char filename[30] = "02_records.txt";
	STUDENT s[N];
	getRecs(filename, s, N);
	Sort(s, N);
	Display(s, N);
	return 0;
}
