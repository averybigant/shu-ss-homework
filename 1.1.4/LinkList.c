/* LinkList.c 		无须修改 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

/* 置一个空链表（仅含头结点）*/
void InitList(struct Node *head)
{
	head->next = NULL;
}

/* 插入一个新结点到链表成为第一个结点 */
void Insert0(struct Node *head, struct Node node)
{
	struct Node *p;
	if(Search(*head, node.data.id)!=NULL)
		return;
	p = (struct Node*)malloc(sizeof(struct Node));
	*p = node;
	p->next = head->next;
	head->next = p;
}

/* 插入一个新结点到链表成为尾结点 */
void Insert1(struct Node *head, struct Node node)
{
	struct Node *p, *q;
	if(Search(*head, node.data.id)!=NULL)
		return;
	p = (struct Node*)malloc(sizeof(struct Node));
	*p = node;
	
	if(head->next==NULL)
	{
		p->next = head->next;
		head->next = p;
		return;
	}
	for(q=head->next; q->next!=NULL; q=q->next)
		;					/* 循环结束后q指向尾结点，即q->next为NULL */
	q->next = p;
	p->next = NULL;
}

/* 按学号序插入一个新结点到链表 */
void Insert(struct Node *head, struct Node node)
{
	struct Node *p, *q;
	if(head->next==NULL || node.data.id < head->next->data.id)
	{
		p = (struct Node*)malloc(sizeof(struct Node));
		*p = node;
		p->next = head->next;
		head->next = p;
/*		printf("已经添加一个新结点\n"); */
/*		Show(p); */
		return;
	}
	if(node.data.id == head->next->data.id)
	{
		Show(head->next);
		printf("编号为 %d 的结点已经存在，不添加新结点\n", node.data.id);
		return;
	}
	
	for(q=head->next; q->next!=NULL && q->next->data.id < node.data.id; q=q->next)
		;
	if(q->next!=NULL && q->next->data.id == node.data.id)
	{
		Show(q->next);
		printf("编号为 %d 的结点已经存在，不添加新结点\n", node.data.id);
		return;
	}
	
	p = (struct Node*)malloc(sizeof(struct Node));
	*p = node;
	p->next = q->next;
	q->next = p;
/*	printf("已经添加一个新结点\n"); */
/*	Show(p); */
}

/* 按学号删除一个结点 */
int Delete(struct Node *head, int id)
{
	struct Node *p, *q;
	
	if(head->next==NULL)
		return 0;
	p = head->next;
	if(p->data.id == id)
	{
		head->next = p->next;
		Show(p);
		printf("被删除\n");
		free(p);
		return 1;
	}
	while(p->next!=NULL && p->next->data.id!=id)
		p = p->next;
	if(p->next != NULL)
	{
		q = p->next;
		p->next = q->next;
		Show(q);
		printf("被删除\n");
		free(q);
		return 1;
	}
	else
	{
		printf("查无此人\n");
		return 0;
	}
}

/* 释放除头结点外的链表所有结点 */
void FreeList(struct Node *head)
{
	struct Node *p;
	while(head->next)
	{
		p = head->next;
		head->next = p->next;
		free(p);
	}
}

/* 输出指定结点的数据 */
void Show(struct Node *p)
{
	if(p!=NULL)
	{
		printf("%08d\t%-12s\t%.2f\t%s\n", p->data.id, p->data.name, p->data.height,
					(p->data.sex==0)?"0(男)":"1(女)");
	}
}

/* 打印单向链表所有结点的数据 */
void ShowList(struct Node head)
{
	struct Node *p;
	printf("  学号  \t  姓名  \t身高\t性别\n");
	for(p=head.next; p!=NULL; p=p->next)
		Show(p);
}

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

/* 从文件中读取数据，追加结点到链表尾部 */
void Load(struct Node *head, char *filename)
{
	FILE *fp;
	char str[20];
	struct Node x;

	if((fp=fopen(filename, "r"))==NULL)
	{
		printf("can not open file \"%s\"!\n", filename);
		return;
	}
	while(!feof(fp))
	{
		if(fgetline(fp, str, 20, '\t')==NULL)
			break;
		x.data.id = atoi(str);

		if(fgetline(fp, str, 20, '\t')==NULL)
			break;
		strncpy(x.data.name, str, 9);
		x.data.name[9] = '\0';
		
		fgetline(fp, str, 20, '\t');
		x.data.height = atof(str);
		
		fgetline(fp, str, 20, '\n');
		x.data.sex = atoi(str);

		Insert1(head, x);		
	}
	fclose(fp);
}

/* 保存链表数据到文件 */
void Save(struct Node head, char *filename)
{
	FILE *fp;
	struct Node *p;
	if((fp=fopen(filename, "w"))==NULL)
	{
		printf("Can't open \"%s\".\n", filename);
		return;
	}
	for(p=head.next; p!=NULL; p=p->next)
		fprintf(fp, "%d\t%s\t%.2f\t%d\n",
					p->data.id, p->data.name, p->data.height, p->data.sex);
	fclose(fp);
	printf("数据已经存入文件 \"%s\".\n", filename);
}

/* 按学号查询（若查到则返回该结点的地址，否则返回空地址） */
struct Node *Search(struct Node head, int id)
{
	struct Node *p;
	for(p=head.next; p!=NULL; p=p->next)
		if(p->data.id == id)
			break;
	return p;
}

/* 修改结点数据（身高）。 注：修改其他数据是类似的。*/
void Modify(struct Node *p, double height)
{
	if(p==NULL)
		return;
	p->data.height = height;
}

/* 单链表按学号升序排序 */
void Sort_id(struct Node *head)
{
	struct Node *p, *q;

	if(head->next==NULL || head->next->next==NULL)
		return;					/* 原链表为空，或仅有一个结点（无须处理） */
	p = head->next->next;		/* 至少有两个结点时，从第二个结点起 */
	head->next->next = NULL;	/* 使原链表仅含第一个结点 */
	while(p!=NULL)				/* 依次将p所指的结点卸下，再插入到原链表的适当位置 */
	{
		q = p;
		p = p->next;
		Insert(head, *q);
	}
}

/* 对单链表进行结点倒置 */
void Reverse(struct Node *head)
{
	struct Node *p, *q;

	if(head->next==NULL || head->next->next==NULL)
		return;					/* 原链表为空，或仅有一个结点（无须处理） */
	p = head->next->next;		/* 至少有两个结点时，从第二个结点起 */
	head->next->next = NULL;	/* 使原链表仅含第一个结点 */
	while(p!=NULL)				/* 依次将p所指的结点卸下，再插入到原链表的首部 */
	{
		q = p;
		p = p->next;
		q->next = head->next;
		head->next = q;
	}
}
