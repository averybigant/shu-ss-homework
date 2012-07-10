#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


void InitList(Node *head){
	head->next = NULL;
}

void Insert1(Node *head, Node node){
	Node *ap;
	ap = (Node*)malloc(sizeof(Node));
	*ap = node;
	ap->next = NULL;
	for (; head->next!=NULL; head = head->next) ;
	head->next = ap;
}

void FreeList(Node *head){
	Node *p;
	while(head->next){
		p = head->next;
		head -> next = p ->next;
		free(p);
	}
}

void Show(Node *p){
	printf("%05d\t%-12s\t%d\n", p->stnum, p->name, p->score);
}
void ShowList(Node *head){
	Node *p;
	for (p = head; p->next!=NULL; p=p->next) 
		Show(p->next);
}

int countbigger(Node *head, int score){
	Node *p;
	int sum=0;
	for (p = head; p->next!=NULL; p=p->next) 
		if((*(p->next)).score >= score)sum++;
	return sum;
}



Node *sort_score(Node *head){
	Node temp;
	Node *newnode,*p, *newhead, *tp;
	int i=0;
	newnode = malloc(sizeof(Node)*countbigger(head, 0));
	newhead = newnode;
	newnode->next=NULL;
	for (temp = *head; temp.next!=NULL; temp=*(temp.next)) {
			i++;
			/*for (; newnode->next!=NULL; newnode=newnode->next) {*/
			for(tp = newhead;tp->next!=NULL && tp->next->score >= temp.next->score;tp = tp->next);
					p = (Node*)malloc(sizeof(Node));
					*p = *(temp.next);
					p->next = (*tp).next;
					(*tp).next = p;
				/*newnode=newnode->next;*/
			/*}*/
	}
	FreeList(head);
	return newhead;
}


void addnode(Node *head){
	while(1){
		Node node;
		printf("import id(<0 for exit):");
		scanf("%d",&node.stnum);
		if(node.stnum<0)break;
		printf("import name: ");
		gets(node.name);//abandon \n
		gets(node.name);
		printf("import score:");
		scanf("%d", &node.score);
		Insert1(head, node);
	}
}

void split(Node *head, Node *lp, Node *lf){
	Node *p;
	for (p = head; p->next!=NULL; p=p->next) {
		if((p->next->score)>=60)Insert1(lp, *(p->next));
		else Insert1(lf, *(p->next));
	}

}

