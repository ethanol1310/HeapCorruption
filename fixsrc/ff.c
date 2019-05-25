#include <stdio.h>
#include <stdlib.h>

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
	if(!CheckFreed(head, *ptr)) {
		InsertListFreed(head, *ptr);
		free(*ptr);
	}
}

void *MallocS(void **ptr, struct ListFreed **head, int size) {
	*ptr = malloc(size);
	DeleteListFreed(head, *ptr);
	return *ptr;
}

int main()
{
	struct ListFreed *list = NULL;
	printf("Allocating 3 strings.\n");
	char *a = malloc(32);
	char *b = malloc(32);
	char *c = malloc(32);

	printf("a malloc(32): %p\n", a);
	printf("b malloc(32): %p\n", b);
	printf("c malloc(32): %p\n", c);

	printf("Freeing a...\n");
	FreeS((void *)&a, &list);
	

	printf("Freeing b...\n");
	FreeS((void *)&b, &list);

	printf("Freeing a again...  ---> Double free\n");
	FreeS((void *)&a, &list);

	printf("Allocating 3 strings.\n");
	printf("1st malloc(32): %p\n", MallocS((void *)&a, &list, 32));
	printf("2nd malloc(32): %p\n", malloc(32));
	printf("3rd malloc(32): %p  ---> Double free\n", malloc(32));
	
	return 0;
}
