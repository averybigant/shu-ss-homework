/* SeqList.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"

/* 从文件中读取字符串。若直接遇到文件结束则返回空地址（NULL） */
char *fgetline(FILE *fp, char *str, int n, char delim)
{	/* 读取文件中的字符串，长度不超过n、遇到delim指定的字符为止，并将该字符换成串结束标志字符 */
	int i, len, cur;
	
	cur = ftell(fp);				/* 找出文件内容指针当前位置 */
	fseek(fp, 0L, SEEK_END);		/* 文件内容指针移至文件尾部 */
	len = ftell(fp);				/* 文件内容指针的当前位置：即文件长度 */
	fseek(fp, cur, SEEK_SET);		/* 恢复文件内容指针位置 */
	if(cur>=len)
	{
		str[0] = '\0';
		return NULL;
	}
	for(i=0; i<n-1 && cur<len && (str[i]=fgetc(fp))!=delim; i++,cur++)
		; 							/* 在指定长度内，并且未到文件尾，并且未遇到指定字符 */
	str[i] = '\0';					/* 追加或替换成字符串结束标志字符 */
	return str;
}

/* 置一个空表 */
void InitList(SeqList *lp)
{
	lp->last = 0;
}

/* 建一个学生顺序表 */
void CreateList(SeqList *lp, char *strname)
{
	FILE *fp;
	char str[20];

	if((fp=fopen(strname, "r"))==NULL)
	{	
		Error("can not open file !");
	}

	while(fgetline(fp, str, 20, '\t')!=NULL)
	{
		lp->data[lp->last].id = atoi(str);
		
		fgetline(fp, str, 20, '\t');
		strncpy(lp->data[lp->last].name, str, 9);
		lp->data[lp->last].name[9] = '\0';
		
		fgetline(fp, str, 20, '\t');
		lp->data[lp->last].height = atof(str);

		fgetline(fp, str, 20, '\n');
		lp->data[lp->last].sex = atoi(str);
		
		lp->last++;
	}
	fclose(fp);
}

/* 按学号排序 */
void Sort_id(SeqList  *lp)
{
	int i, j, k;
	datatype st;

	for(i=0; i<lp->last-1; i++)
	{
		k = i;
		for(j=i+1; j<lp->last; j++)
			if(lp->data[j].id < lp->data[k].id)
				k = j;
		if(k!=i)
		{
			st = lp->data[k];
			lp->data[k] = lp->data[i];
			lp->data[i] = st;
		}
	}
}

/* 自定义错误处理函数 */
void Error(char *s)
{
	printf("\n %s\n", s);
	exit(1);				/* 返回操作系统，该函数声明在stdlib.h中 */
}

/* 输出学生顺序表 */
void PrintList(SeqList *lp)
{
	int i;
	for(i=0; i<lp->last; i++)
		printf("%08d\t%-11s\t%.2f\t%d\n",
			lp->data[i].id, lp->data[i].name, lp->data[i].height, lp->data[i].sex);
}

/* 保存学生顺序表到指定文件 */
void Save(SeqList *lp, char *strname)
{
	FILE *fp;
	int i;
	if((fp=fopen(strname, "w"))==NULL)
	{
		Error("can not open file !");
	}
	for(i=0; i<lp->last; i++)
	{
		fprintf(fp, "%08d\t%s\t%5.2f\t%2d\n",
					lp->data[i].id, lp->data[i].name, lp->data[i].height, lp->data[i].sex);
	}
	fclose(fp);
}



void Insert(SeqList *lp, datatype x){
	/*SeqList must be sorted at first*/
	int i, j;
	for (i = 0; i < lp->last - 1; i++) {
		if(i+1 > lp->last || (lp->data[i].id <= x.id && x.id < lp->data[i+1].id)){
			for (j = lp->last; j >= i+1; j--) {
				lp->data[j + 1] = lp->data[j];
			}

			break;
		}
	}
	lp->data[i + 1] = x;
	lp->last++;
}


void Reverse(SeqList *lp){
	int i, swp;
	datatype temp;
	swp = lp->last-1;
	/*for (i = 0 ; i < swp; i++, swp=lp->last-i) {*/
	for (i = 0 ; i < swp; i++, swp--) {
		temp = lp->data[i];
		lp->data[i] = lp->data[swp];
		lp->data[swp] = temp;
	}
}

int Count(SeqList *lp, double y){
	int i;
	int sum=0;
	for (i = 0; i < lp->last; i++) 
		if(lp->data[i].height == y)sum++;
	return sum;
}
void Split(SeqList *lp, SeqList *lpm, SeqList *lpfm){
	int i;
	for (i = 0; i < lp->last; i++) {
		if(lp->data[i].sex==0)Adddata(lpm, lp->data[i]);
		else
			Adddata(lpfm, lp->data[i]);
	}
}


void Adddata(SeqList *lp, datatype x){
	lp->data[lp->last] = x;
	lp->last++;
}

int Pause(char * prompt){
	printf("%s", prompt);
	return getchar();
}
