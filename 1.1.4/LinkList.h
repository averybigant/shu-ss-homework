/* LinkList.h		无须修改 */
#ifndef LINKLIST_H
#define LINKLIST_H

/* 单链表结点类型 */
typedef struct
{
	int id;					/* 学号 */
	char name[9];			/* 姓名 */
	double height;			/* 身高 */
	int sex;				/* 性别，0为男生，1为女生 */
} datatype;

struct Node
{
	datatype data;			/* 数据域 */
	struct Node *next;		/* 指针域 */
};

/* 带表头的单链表的基本运算函数 */
/* 约定：头结点一般不为动态结点，故也无须释放头结点 */
void InitList(struct Node *head);				/* 置一个空表（带头结点）               */

void Insert0(struct Node *head, struct Node node);/* 插入一个新结点到链表成为第一个结点  */
void Insert1(struct Node *head, struct Node node);/* 插入一个新结点到链表成为尾结点      */
void Insert(struct Node *head, struct Node node); /* 按学号序插入一个新结点到链表        */

int  Delete(struct Node *head, int id);			/* 按学号删除一个结点                   */
void FreeList(struct Node *head);				/* 释放除头结点外的链表所有结点         */

void Show(struct Node *p);						/* 输出指定结点的数据                   */
void ShowList(struct Node head);				/* 打印单向链表所有结点的数据           */

void Load(struct Node *head, char *filename);	/* 从文件中读取数据，追加结点到链表尾部 */
void Save(struct Node head, char *filename);	/* 保存链表数据到文件                   */

struct Node *Search(struct Node head, int id);	/* 按学号查询                           */
void Modify(struct Node *p, double height);		/* 修改结点数据（身高）                 */

void Sort_id(struct Node *head);				/* 单链表按学号升序排序                 */
void Reverse(struct Node *head);				/* 对单链表进行结点倒置                 */

char *fgetline(FILE *fp, char *str, int n, char delim);	/* 从文件中读取字符串           */

#endif
