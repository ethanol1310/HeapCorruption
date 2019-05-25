#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListFreed {
	void *data;
	struct ListFreed *next;
};

int ListLength(struct ListFreed *head){
	struct ListFreed *cur = head;
	int count = 0;
	
	while(cur != NULL){
		count++;
		cur = cur->next;
	}
	return count;
}

void InsertListFreed(struct ListFreed **head, void *data) {
	struct ListFreed *nodePtr, *prevNode, *newNode;
	
	newNode = (struct ListFreed*)malloc(sizeof(struct ListFreed));
	if(!newNode) {
		return;
	}

	nodePtr = *head;
	newNode->data = data;
	if(nodePtr == NULL) {
		newNode->next = nodePtr;
		*head = newNode;
	}
	else {
		while(nodePtr != NULL){
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		prevNode->next = newNode;
		newNode->next = nodePtr;	
	}
}

void DeleteListFreed (struct ListFreed **head, void *data) {
	struct ListFreed *nodePtr, *prevNode;
	if(*head == NULL) {
		return;
	}

	if((*head)->data == data) {
		*head = (*head)->next;
		return;
	}
	else {
		nodePtr = *head;
		
		while(nodePtr != NULL && nodePtr->data != data) {
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if(nodePtr) {
			prevNode->next = nodePtr->next;
		}
	}
}

int CheckFreed(struct ListFreed **head, void *data) {
	struct ListFreed *nodePtr;
	
	if(*head == NULL)
		return 0;
	nodePtr = *head;

	while(nodePtr != NULL && nodePtr->data != data) {
		nodePtr = nodePtr->next;
	}

	if (nodePtr) 
		return 1;
	else
		return 0;
}

void FreeS(void **ptr, struct ListFreed **head) {
	InsertListFreed(head, *ptr);
	free(*ptr);
}

void *MallocS(void **ptr, struct ListFreed **head, int size) {
	*ptr = malloc(size);
	DeleteListFreed(head, *ptr);
	return *ptr;
}

int main(int argc, char **argv)
{
	struct ListFreed *list = NULL;
	char *a = malloc(128);
	char *b = malloc(128);
	
	strcpy(a, "string a");
	strcpy(b, "string b");

	printf("address a: %p\n", a);
	printf("string a: %s\n", a);
	printf("address b: %p\n", b);
	printf("string b: %s\n", b);

	printf("freeing a...\n");
	FreeS((void *)&a, &list);
	MallocS((void *)&a, &list, 128);
	if (!CheckFreed(&list, a))
	{
		printf("address a: %p\n", a);
		printf("string a: %s\n", a);
		printf("put a string here (write after free): string c\n");
		strcpy(a, "string c");	

		printf("address a: %p\n", a);
		printf("string a: %s\n", a);	
	}
	return 0;
}
