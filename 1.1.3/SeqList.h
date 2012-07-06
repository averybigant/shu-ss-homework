/* SeqList.h */
#ifndef SEQLIST_H
#define SEQLIST_H

typedef struct
{
	int id;			/* 学号 */
	char name[9];	/* 姓名 */
	double height;	/* 身高 */
	int sex;
} datatype;

#define MAX 50

typedef struct
{
	datatype data[MAX];	/* 存放顺序表元素的数组 */
	int last;			/* 表示data中实际存放元素个数 */
}SeqList;

void InitList(SeqList *lp);						/* 置一个空表 */
void CreateList(SeqList *lp, char *strname);	/* 建一个学生顺序表 */
void Sort_id(SeqList *lp);						/* 按学号排序 */
void Error(char *s);							/* 自定义错误处理函数 */
void PrintList(SeqList *lp);					/* 输出学生表 */
void Save(SeqList *lp, char *strname);			/* 保存学生顺序表到指定文件 */

void Insert(SeqList *lp, datatype x);
void Reverse(SeqList *lp);
 int Count(SeqList *lp, double y);
void Split(SeqList *lp, SeqList *lpm, SeqList *lpfm);
void Adddata(SeqList *lp, datatype x);
int Pause(char * prompt);

#endif
