#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node {
	struct Node *next;
	char *string;
	int freq;
} node;

node *read_file(char *file_name)
{
	char *fn = (char *)malloc(sizeof(char) * 32);
	strcpy(fn, file_name);
	char *mode = "r";
	FILE *fp = fopen(fn, mode);
	free(fn);
	assert(fp);

	node *head = NULL;
	while (!feof(fp)) {
		char *word = (char *)malloc(sizeof(char) * 32);
		fscanf(fp, "%s", word);
		node *newNode = (node *)malloc(sizeof(node));
		newNode->string = (char *)malloc(strlen(word));
		strcpy(newNode->string, word);
		newNode->freq = 1;
		newNode->next = head;
		head = newNode;
		free(word);
	}
	fclose(fp);
	return head;
}

void delete (node *head, node *entry)
{
	node **indirect = &head;
	while ((*indirect) != entry)
		indirect = &((*indirect)->next);
	*indirect = entry->next;
	free(entry);
}

int find(node *head, char *word)
{
	node *pt = head;
	while (pt != NULL) {
		if (!strcmp(pt->string, word))
			return 1;
		pt = pt->next;
	}
	return 0;
}

void print_list(node *head)
{
	node *pt = head;
	while (pt != NULL) {
		printf("[%x]: %s -> %d\n", pt, pt->string, pt->freq);
		pt = pt->next;
	}
}

int main(int argc, char **argv)
{
	assert(argc == 2);
	node *head = read_file(argv[1]);
	print_list(head);
	return 0;
}
