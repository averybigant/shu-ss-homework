/* file4.c 有3个函数待完成 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* 统计head为头结点的学生链表中身高达标（女生身高、男生身高标准依次为第2,3个参数给定）人数并返回 */
int Count(struct Node head, double height_fm, double height_m)		/* 待完成 */
{
	int n=0;
	struct Node p;
	double thisstandard;
	for (p = *(head.next); p.next!=NULL; p=*(p.next) ) {
		thisstandard = p.data.sex?height_fm:height_m;
		if(p.data.height >= thisstandard)n++;
	}
	return n;
}

/* 将head为头结点的学生链表拆分成男生链表hm与女生链表hfm */
void Split(struct Node *head, struct Node *hm, struct Node *hfm)	/* 待完成 */
{
	struct Node p;
	for (p = *(head->next); p.next!=NULL; p=*(p.next)) {
		if(p.data.sex)Insert1(hfm, p);
		else Insert1(hm, p);
	}
	if(p.data.sex)Insert1(hfm, p);
	else Insert1(hm, p);
}

/* 将男生链表hm与女生链表hfm，合并成一条链表head */
void Merge(struct Node *hm, struct Node *hfm, struct Node *head)	/* 待完成 */
{
	struct Node p;
	for (p = *(hm->next); p.next!=NULL; p=*(p.next)) 
		Insert(head, p);
	Insert(head, p);
	for (p = *(hfm->next); p.next!=NULL; p=*(p.next)) 
		Insert(head, p);
	Insert(head, p);
		
}

int Pause(char *prompt)
{
	printf("%s", prompt);
	return getchar();
}

int main()
{
	int choice, id;
	double height;
	struct Node head, hm, hfm, x, *p;

	InitList(&head);
	InitList(&hm);
	InitList(&hfm);
	while(1)
	{
		printf("\n\t                单向链表程序\n");
		printf("\t===========================================\n");
		printf("\t 1 -- 添加一个结点\t 7 -- 倒        序\n");
		printf("\t 2 -- 删除一个结点\t 8 -- 读   文   件\n");
		printf("\t 3 -- 输出整个链表\t 9 -- 写   文   件\n");
		printf("\t 4 -- 查        询\t A -- 拆 分  链 表\n");
		printf("\t 5 -- 修 改  数 据\t B -- 输出男女链表\n");
		printf("\t 6 -- 按学号 排 序\t C -- 合 并  链 表\n");
		printf("\t 0 -- 退        出\n");
		printf("\t===========================================\n");
		choice = Pause("\t 请选择 ");
		if(choice=='0')
			break;
		printf("\n");
		switch(choice)
		{
		case '1':	printf("\n添加一个结点\n请输入该结点的学号:");
					scanf("%d", &x.data.id);
					gets(x.data.name);			/* “吃掉”换行字符 */
					printf("姓名: ");
					gets(x.data.name);
					printf("身高: ");
					scanf("%lf", &x.data.height);
					printf("性别(0--男，1--女): ");
					scanf("%d", &x.data.sex);
					Insert(&head, x);
					break;
		case '2':	printf("\n删除一个结点\n请输入该结点的学号:");
					scanf("%d", &id);
					Delete(&head, id);
					break;
		case '3':	ShowList(head);	break;
		case '4':	printf("\n查询结点\n请输入欲查询结点的学号:");
					scanf("%d", &id);
					p = Search(head, id);
					if(p==NULL)
						printf("\n查无此人.\n");
					else
						Show(p);
					break;
		case '5':	printf("\n修改身高数据\n请输入该结点的学号:");
					scanf("%d", &id);
					p = Search(head, id);
					if(p==NULL)
						printf("\n查无此人.\n");
					else
					{
						printf("\n原始数据:\n");
						Show(p);
						printf("\n请输入新的身高值: ");
						scanf("%lf", &height);
						Modify(p, height);
						printf("\n修改结果:\n");
						Show(p);
					}
					break;
		case '6':	printf("\n按学号排序，处理完毕.\n");
					Sort_id(&head);
					break;
		case '7':	printf("\n倒序处理，处理完毕.\n");
					Reverse(&head);
					break;
		case '8':	printf("\n读取文件records.txt中的数据，追加到链表尾部.\n");
					Load(&head, "records.txt");
					break;
		case '9':	printf("\n将链表中的数据写入 results.txt 文件中。\n");
					Save(head, "results.txt");
					break;
		case 'A':
		case 'a':	printf("\n拆分链表:将链表拆分成男生链表、女生链表.\n");
					Split(&head, &hm, &hfm);
					break;
		case 'B':
		case 'b':	printf("\n男生链表\n");
					ShowList(hm);
					printf("\n女生链表\n");
					ShowList(hfm);
					break;
		case 'C':
		case 'c':	printf("\n将男生链表、女生链表合并成一条链表.\n");
					Merge(&hm, &hfm, &head);
					break;
		}
		choice = getchar();
	}
	FreeList(&head);
	FreeList(&hm);
	FreeList(&hfm);
	return 0;
}
