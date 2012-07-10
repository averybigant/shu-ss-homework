#include <stdio.h>
#include <stdlib.h>
#define LINEMAX 10

typedef struct node{
	int data;
	struct node *next;
}node;

void Init(node *head){
	head -> next = NULL;
}

void create(node *head, int data){
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode -> data = data;
	newnode -> next = head -> next;
	head -> next = newnode;
}

void freelist(node *head){
	node *p;
	for (p = head; p->next!=NULL; p=p->next)
		free(p->next);
}

int count(node *head){
	int i;
	for(i=1;head->next!=NULL;i++);
	return i;
}

node *sort(node *head){
	node *newlist, *p, *newnode;
	node temp;

	/*head = *headp;*/
	newlist = malloc(sizeof(node));
	newlist->next = NULL;
	
	for (temp = *head; temp.next!=NULL; temp=*(temp.next)) {
		for (p = newlist; p->next!=NULL && p->next->data>=temp.next->data; p=p->next);
		newnode = (node*)malloc(sizeof(node));
		*newnode = *(temp.next);
		newnode->next = p->next;
		p->next = newnode;
	}
	freelist(head);
	return newlist;
}

void showlist(node *head){
	node *p;
	int i=1;
	for (p = head; p->next!=NULL; p=p->next){
		printf("%4d ", p->next->data);
		if(i % LINEMAX == 0)printf("\n");
		i++;
	}
	printf("\n");
}

int main(void)
{
	int n, i, data;
	node list;
	FILE *fp;

	Init(&list);
	fp = fopen("./data.txt", "r");
	fscanf(fp, "%d\n", &n);
	for (i = 0; i < n; i++) {
		do{
			fscanf(fp, "%d", &data);
			create(&list, data);
		}while(fgetc(fp)!='\n');

		printf("Case %d:\n", i+1);
		printf("Before sorting:\n");
		showlist(&list);
		list = *sort(&list);
		printf("After sorting:\n");
		showlist(&list);
		freelist(&list);
		Init(&list);
	}
	freelist(&list);
	return 0;
}
