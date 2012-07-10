#include <stdio.h>
#include "linklist.h"

int main(void)
{
	Node linklist, lp, lf;
	printf("hello~\n");

	InitList(&linklist);
	InitList(&lp);
	InitList(&lf);

	addnode(&linklist);
	printf("总名单：\n");
	ShowList(&linklist);
	linklist = *sort_score(&linklist);
	printf("成绩排名：\n");
	ShowList(&linklist);
	printf("\n\n");
	printf("及格人数/总人数: %d/%d\n", countbigger(&linklist, 60), countbigger(&linklist, 0));
	split(&linklist, &lp, &lf);
	printf("及格名单：\n");
	printf("学号\t  姓名  \t分数\n");
	ShowList(&lp);
	printf("不及格名单：\n");
	printf("学号\t  姓名  \t分数\n");
	ShowList(&lf);
	FreeList(&linklist);
	FreeList(&lp);
	FreeList(&lf);
	return 0;
}
