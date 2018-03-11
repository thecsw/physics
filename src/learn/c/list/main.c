#include<stdio.h>
#include<stdlib.h>

typedef struct nodejs {
	int value;
	struct nodejs* next;
} node;

node* BuildList(){
	node* head = NULL;
	
	for (int i = 5; i >= 0; i--) {
		node* newNode = (node*)malloc(sizeof(node));
		newNode->value = i;
		newNode->next = head;
		head = newNode;
	}
	return head;
}

void push(node** head_ref, int new_data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->value = new_data;
	newNode->next = (*head_ref);
	(*head_ref) = newNode;
}

void insert(node* prev_node, int new_data) {
	if (prev_node == NULL) {
		printf("Can't do it in front of a null");
		return;
	}
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(node** head, int new_data) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = new_data;
	new_node->next = NULL;
	node* last = *head;

	if (*head == NULL) {
		*head = new_node;
		return;
	}

	while (last->next != NULL)
		 last = last->next;

	last->next = new_node;
}

void printlist(node* node) {
	while(node != NULL) {
		printf("\t%d\t(%#x)\n", node->value, node);
		node = node->next;
	}
}

int main() {
	node *head = BuildList();
	push(&head, 10);
	insert(head->next, 90);
	printlist(head);
}
