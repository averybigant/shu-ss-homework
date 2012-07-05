#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 60

typedef struct{
	char sid[10];
	char sname[20];
	double stall;
}STUDENTS;

char *fgetlines(FILE *fp, char *str, int n, char delim);
void Display(STUDENTS *s, int n);
void Sort(STUDENTS *s, int n);
int getRecs(char *filename, STUDENTS *s, int n);

char *fgetlines(FILE *fp, char *str, int n, char delim){
	int cur, len, i;
	cur = ftell(fp);
	fseek(fp, 0L, SEEK_END);
	len = ftell(fp);
	fseek(fp, cur, SEEK_SET);
	if(cur>=len){
		str[0] = '\0';
		return NULL;
	}

	for(i=0; i<n && (str[i] = fgetc(fp)) != delim && cur<len; i++,cur++);
	str[i] = '\0';
	return str;
}

int getRecs(char *filename, STUDENTS *s, int n){
	int i;
	char str[20];
	FILE *fp;
	if((fp=fopen(filename, "r"))==NULL)return 0;
	for (i = 0; i < n && fgetlines(fp, str, 20, '\t'); i++) {
		strcpy(s->sid, str);
		fgetlines(fp, str, 20, '\t');
		strcpy(s->sname, str);
		fgetlines(fp, str, 20, '\n');
		s->stall = atof(str);
		s++;
	}
	fclose(fp);
	return i;
}

void Sort(STUDENTS *s, int n){
	int i, j, k;
	STUDENTS stemp;
	for (i = 0; i < n; i++) {
		k = i;
		for (j = i+1; j < n; j++) 
			if( s[j].stall<s[k].stall )k=j;
		if(k!=i){
			stemp = s[k];
			s[k] = s[i];
			s[i] = stemp;
		}
	}
}

void Display(STUDENTS *s, int n){
	int i;
	for (i = 0; i < n; i++){
		printf("%s\t%s\t%.2lf\n", s->sid, s->sname, s->stall);
		s++;
	}
}

int main(void)
{
	STUDENTS s[N];
	int n;
	n = getRecs("./02_records.txt", s, N);
	Sort(s, n);
	Display(s, n);
	return 0;
}
