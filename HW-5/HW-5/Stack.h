#include<stdlib.h>

struct TNode
{
	void* value;
	struct TNode* next;
};

typedef struct TNode TNode;

struct TStack
{
	TNode* head;
	int size;
	int maxSize;
};

typedef struct TStack TStack;

int push(TStack* Stack, void* value)
{
	if (Stack->size >= Stack->maxSize)
	{
		return -1;
	}
	TNode* tmp = (TNode*)malloc(sizeof(TNode));
	tmp->value = value;
	tmp->next = Stack->head;
	Stack->head = tmp;
	Stack->size++;
	return 0;
}

void* pop(TStack* Stack)
{
	if (Stack->size == 0)
	{
		return NULL;
	}
	TNode* tmp = NULL;
	void* value = Stack->head->value;
	tmp = Stack->head;
	Stack->head = Stack->head->next;
	free(tmp);
	Stack->size--;
	return value;
}

void EraseStack(TStack* Stack)
{
	TNode* current = Stack->head;
	TNode* next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	Stack->head = NULL;
	Stack->size = 0;
}
