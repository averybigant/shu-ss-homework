#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"
/* vim:set tags+=../tags: */
int main(void)
{
	SeqList lp, lpm, lpfm;
	datatype x;
	double height;

	InitList(&lp);
	InitList(&lpm);
	InitList(&lpfm);
	CreateList(&lp, "./03_records.txt");
	printf("1: 信息表\n");
	PrintList(&lp);
	
	Sort_id(&lp);
	printf("2: 排序后的信息表\n");
	PrintList(&lp);
	Save(&lp, "03_save.txt");

	printf("3: 插入后保持有序\n");
	printf("Input id:");
	scanf("%d", &x.id);
	printf("Input name:");
	scanf("%s", x.name);
	printf("Input height:");
	scanf("%lf", &x.height);
	printf("Input sex:");
	scanf("%d", &x.sex);
	Insert(&lp, x);
	PrintList(&lp);

	printf("4: reverse\n");
	Reverse(&lp);
	PrintList(&lp);

	printf("5: find height\n");
	printf("Input height value:");
	scanf("%lf", &height);
	printf("There are %d %.2lf .\n", Count(&lp, height), height);


	printf("6: split\n");
	Reverse(&lp);
	Split(&lp, &lpm, &lpfm);
	printf("MALE:\n");
	PrintList(&lpm);
	printf("FEMALE\n");
	PrintList(&lpfm);

	return 0;
}
