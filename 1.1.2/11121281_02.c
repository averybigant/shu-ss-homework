/* SeqList.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seqlist.h"

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
		lp->data[lp->last].name[8] = '\0';
		
		fgetline(fp, str, 20, '\n');
		lp->data[lp->last].height = atof(str);

		
		lp->last++;
	}
	fclose(fp);
}

/* 按身高排序c */
void Sort_height(SeqList  *lp)
{
	int i, j, k;
	datatype st;

	for(i=0; i<lp->last-1; i++)
	{
		k = i;
		for(j=i+1; j<lp->last; j++)
			if(lp->data[j].height < lp->data[k].height)
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
		printf("%08d\t%-10s\t%.2f\n",
			lp->data[i].id, lp->data[i].name, lp->data[i].height);
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
		fprintf(fp, "%08d\t%s\t%5.2f\n",
					lp->data[i].id, lp->data[i].name, lp->data[i].height);
	}
	fclose(fp);
}

int main(void)
{
	SeqList lp;
	InitList(&lp);
	CreateList(&lp, "02_records.txt");
	Sort_height(&lp);
	PrintList(&lp);
	
	return 0;
}
