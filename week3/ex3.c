#include <stdio.h>
#include <stdlib.h>

typedef struct node {  
    int value;	
    struct node * next; 
} node_sl; 

int print_list(node_sl **head){
	node_sl *p = *head;
	while(p!=NULL){
		printf("%d ", p->value);
		p = p->next;
	}
	printf("\n");
}

int insert_node(node_sl **head, int val, int pos){ 
	node_sl *p = *head; 
	node_sl *q = NULL; 
	for(int i=0; i<pos-1; i++){
		if(p==NULL){
			return 0;
		}
		p=p->next;
	} 
	q = malloc(sizeof(node_sl));
	q ->value = val; 
	q ->next = p->next;
	p->next = q; 
	return 1;
}

int delete_node(node_sl **head, int pos){
	int pop = 0;
	node_sl *p = *head;
	node_sl *q = NULL;
	if(pos==0){
		p = (*head)->next;
		pop =(*head)->value;
		free(*head);
		*head = p;
		return pop;
	}
	int i = 0;
	for (i=0;i<pos-1;i++){
		p = p->next;
	}
	q=p->next;
	pop = q->value;
	p->next=q->next;
	free(q);
	return pop;
}

int main(){
	node_sl *head = NULL;
	head = malloc(sizeof(node_sl));
	head->value = 6; 
	head->next = NULL;
	insert_node(&head, 3, 1);
	insert_node(&head, 10, 2);
	insert_node(&head, 8, 3);
	print_list(&head);
	printf("Deleted: %d\n",delete_node(&head, 0));
	print_list(&head);
}