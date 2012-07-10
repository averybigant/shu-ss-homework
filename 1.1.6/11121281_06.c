#include <stdio.h>
#include <stdlib.h>

typedef struct student{
	int code;
	int status;
	int order;
	struct student *next;
}student;

void Init(student *head){
	head -> next = NULL;
}

void Insert1(student *head, student node){
	student *p, *new;
	for (p = head; p->next!=NULL; p=p->next) ;
	node.next = NULL;
	new = (student*)malloc(sizeof(student));
	*new = node;
	p->next = new;
}

void join(student *head){
	student *p;
	for (p = head; p->next!=NULL; p=p->next);
	p->next = head->next;
}
			

void addnode(student *head, int n){
	int i;
	student node;
	for (i = 1; i <= n; i++) {
		node.order = i;
		node.status = 1;
		scanf("%d", &node.code);
		Insert1(head, node);
	}
}

int main(void)
{
	int n, m, current=0, out=0;
	student list;
	student *p;
	Init(&list);

	printf("input n:");
	scanf("%d", &n);
	printf("input m:");
	scanf("%d", &m);
	printf("input %d codes:\n", n);
	addnode(&list, n);
	join(&list);
	printf("\n==============================\n\n");

	p = list.next;
	while(out < n){
		if(p->status)current++;
		if(current == m){
			printf("%3d", p->order);
			p->status = 0;
			out++;
			m = p->code;
			current = 0;
		}
		p = p->next;
	}
	printf("\n\nDone\n");

	return 0;
}
