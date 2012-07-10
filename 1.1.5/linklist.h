#ifndef LINKLIST_H
#define LINKLIST_H

#define MAX_SIZE 20

/* 单链表结点类型 */
typedef struct student
{
	int stnum, score;
	char name[MAX_SIZE];
	struct student *next;
}Node;


/* 带表头的单链表的基本运算函数 */
/* 约定：头结点一般不为动态结点，故也无须释放头结点 */
void InitList(Node *head);				/* 置一个空表（带头结点）               */
void Insert1(Node *head, Node node);/* 插入一个新结点到链表成为尾结点      */
int  Delete(Node *head, int id);			/* 按学号删除一个结点                   */
void FreeList(Node *head);				/* 释放除头结点外的链表所有结点         */
void Show(Node *p);						/* 输出指定结点的数据                   */
void ShowList(Node *head);				/* 打印单向链表所有结点的数据           */
int countbigger(Node *head, int score);
Node *sort_score(Node *head);				
void addnode(Node *head);
void split(Node *head, Node *lp, Node *lf);



#endif
