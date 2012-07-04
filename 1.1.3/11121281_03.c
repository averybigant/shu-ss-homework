#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"
int main(void)
{
	SeqList lp;
	InitList(&lp);
	CreateList(&lp, "./03_records.txt");
	Sort_id(&lp);
	PrintList(&lp);
	Save(&lp, "03_save.txt");
	return 0;
}
