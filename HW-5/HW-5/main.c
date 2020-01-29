// ================================================================
// ��������!!! ��� ����������� ������� ���� (� Win7) � ���� �������
// � ��������� �������� ����� �� Lucida Console!
// ================================================================

// ���� "��������� � ��������� ������"
// ������������ ������ �5
// ��� ������

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#pragma warning(disable:6011)
#pragma warning(disable:6031)

void menu();
void task01();
void task02();
void task03();
void task04();
void task05();
void task06();

int main(int argc, const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int sel = 0;
	do
	{
		menu();
		scanf("%i", &sel);

		if (sel != 0) { system("cls"); }

		switch (sel)
		{
		case 1: task01();
			break;
		case 2: task02();
			break;
		case 3: task03();
			break;
		case 4: task04();
			break;
		case 5: task05();
			break;
		case 6: task06();
			break;
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	system("cls");
	printf(" 1 - ������ 01 (������� �� ���������� � �������� �������)\n");
	printf(" 2 - ������ 02 (��������� ������������������)\n");
	printf(" 3 - ������ 03 (����������� ������������ ������)\n");
	printf(" 4 - ������ 04 (������� �� ��������� ������ � �����������)\n");
	printf(" 5 - ������ 05 (���������� �������)\n");
	printf(" 6 - ������ 06 (������������ �������)\n\n");
	printf(" 0 - �����\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\n������� <Enter> ��� �����������...");
	getch();
}

// 1. ����������� ������� �� ���������� � �������� ������� ��������� � �������������� �����.
//
// === ������������� ���� ===
// �������� �����
struct TNode
{
	// ������ ������ - ���������������� ������
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

// ���
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

// ���
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

// ������� ����� (�� �� ��������!)
void Erase(TStack* Stack)
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

// ������������� ������ �����
void Init(TStack* Stack, int maxSize)
{
	Stack->maxSize = maxSize;
	Stack->size = 0;
	Stack->head = NULL;
}
// === ����� ������������� ����� ===

// ����� ����� �� ����� (��� ����� � ������� ���� int)
void PrintStackInt(TStack* Stack)
{
	TNode* current = Stack->head;
	while (current != NULL)
	{
		printf("%d", *(int*)current->value);
		current = current->next;
	}
}

// ��������� ������ �� �������� ���� int
int* GetIntP(int num)
{
	int* tmp = (int*)malloc(sizeof(int));
	*tmp = num;
	return tmp;
}

void task01()
{	
	printf("������ 01 (������� �� ���������� � �������� �������)\n\n");
	
	int num;
	
	// ���������� �����
	TStack* Stack = (TStack*)malloc(sizeof(TStack));
	Init(Stack, 100);

	printf("����� � ���������� �������: ");
	scanf("%d", &num);
	while (num != 0)
	{
		// ���� ���� ��� �� ������
		if (Stack->size < Stack->maxSize)
		{
			// ������ � ���� ������� �� ������� �� 2
			push(Stack, GetIntP(num % 2));
			num /= 2;
		}
		else
		{
			printf("������������ �����/n");
		}
	}
	printf("����� � �������� �������: ");
	// �������� �������� � 2-����� �������
	PrintStackInt(Stack);
	printf("\n");
	// �������� � �������� �����
	Erase(Stack);
	free(Stack);

	pause();
}

// 2. �������� ���������, ������� ����������, �������� �� ��������� ���������
// ������������������ ����������.������� ���������� ��������� ��������� : (), ([])(), {}(),
// ([{}]), ������������ � )(, ())({ ), (, ]) }), ([(]) ��� ������[, (, { .
// ��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}].
//
// ��������� ������ �� ������
char* GetCharP(char value)
{
	char* tmp = (char*)malloc(sizeof(char));
	tmp[0] = value;
	tmp[1] = '\0';
	return tmp;
}

void task02()
{
	printf("������ 02 (��������� ������������������)\n\n");

	// ���������� � ������������� �����
	TStack* Stack = (TStack*)malloc(sizeof(TStack));
	Init(Stack, 100);

	// �������� ������
	char* expr = (char*)malloc(100*sizeof(char));

	printf("��������� ������������������: ");
	scanf("%s", expr);

	int index = 0;
	int result = 0;
	void* symbol;

	while (expr[index] != '\0')
	{
		switch (expr[index])
		{
		// ���� ������ �����������, �� ����������� � � ����
		case '(':
		case '[':
		case '{':
		case '<':
			push(Stack, GetCharP(expr[index]));
			break;
		// ���� ������ �����������, �� �������� ������ �� ����� � ��������� ������������
		case ')':
			result = -1;
			symbol = pop(Stack);
			if (symbol != NULL)
			{
				if (*(char*)symbol == '(')
				{
					result = 0;
				}
			}
			break;
		case ']':
			result = -1;
			symbol = pop(Stack);
			if (symbol != NULL)
			{
				if (*(char*)symbol == '[')
				{
					result = 0;
				}
			}
			break;
		case '}':
			result = -1;
			symbol = pop(Stack);
			if (symbol != NULL)
			{
				if (*(char*)symbol == '{')
				{
					result = 0;
				}
			}
			break;
		case '>':
			result = -1;
			symbol = pop(Stack);
			if (symbol != NULL)
			{
				if (*(char*)symbol == '<')
				{
					result = 0;
				}
			}
			break;
		}
		if (result == -1)
		{
			break;
		}
		else
		{
			index++;
		}
	}
	if ((result == 0) && (Stack->size == 0))
	{
		printf("��������� ������������������ ����������\n");
	}
	else
	{
		printf("��������� ������������������ �� ����������\n");
	}
	
	Erase(Stack);
	free(Stack);

	pause();
}

// 3. *������� �������, ���������� ����������� ������ (�� ���� ��������� � ������ �����
// ������������ ������ ��� �������� ������� ������).
//
// ����������� ����� � ������� ���� int
TStack* CopyStackInt(TStack* Stack)
{
	// ������� ����
	TNode* node;
	TNode* newNode;

	// �������� � ������������� ������ �����
	TStack* NewStack = (TStack*)malloc(sizeof(TStack));
	Init(NewStack, Stack->maxSize);

	// ����������� �����
	if (Stack->head != NULL)
	{
		NewStack->head = (TNode*)malloc(sizeof(TNode));
		newNode = NewStack->head;
		node = Stack->head;

		while (node != NULL)
		{
			// ����������� ������
			newNode->value = GetIntP(*(int*)node->value);

			// �������� ���������� ����
			if (node->next != NULL)
			{
				newNode->next = (TNode*)malloc(sizeof(TNode));
				newNode = newNode->next;
			}
			else
			{
				newNode->next = NULL;
			}
			node = node->next;
		}
	}

	return NewStack;
}

// ����� ����� �� ����� (��� ����� � ������� ���� int)
void PrintStackInt2(TStack* Stack)
{
	TNode* current = Stack->head;
	while (current != NULL)
	{
		printf("%d", *(int*)current->value);
		current = current->next;
		
		if (current == NULL)
		{
			printf(".\n");
		}
		else
		{
			printf(", ");
		}
	}
}

void task03()
{
	printf("������ 03 (����������� ������������ ������)\n\n");

	// �������� � ������������� �����
	TStack* Stack = (TStack*)malloc(sizeof(TStack));
	Init(Stack, 10);

	// ���������� ����� �������
	srand(time(NULL));
	for (int i = 0; i <= 10; i++)
	{
		push(Stack, GetIntP(rand() % 100));
	}

	// �������� ����� �����
	TStack* NewStack = CopyStackInt(Stack);
	
	// ����� ���� ������
	printf("������ ����: ");
	PrintStackInt2(Stack);
	printf("������ ����: ");
	PrintStackInt2(NewStack);

	pause();
}

// 4. *����������� �������� �������� �� ��������� ������ ��������������� ��������� �
// �����������
//
void task04()
{
	printf("������ 04 (������� �� ��������� ������ � �����������)\n\n");

	// ���� ������
	int error = 0;
	
	// ��������� ������ ��� �������� � ��������������� ������
	char* expr1 = (char*)malloc(100 * sizeof(char));
	char* expr2 = (char*)malloc(100 * sizeof(char));

	// ��������� ���� ��������
	TStack* Temp = (TStack*)malloc(sizeof(TStack));
	Init(Temp, 100);

	printf("�������� ���������: ");
	scanf("%s", expr1);
	
	// ��������������� ����������
	int ind = 0;
	int ind2 = 0;
	char* ch;

	while (!((expr1[ind] == '\0') && (Temp->size == 0)))
	{
		if (((expr1[ind] >= 'A') && (expr1[ind] <= 'Z')) || ((expr1[ind] >= 'a') && (expr1[ind] <= 'z')))
		{	// ����� - ��� ����������
			expr2[ind2] = expr1[ind];
			ind2++;
			ind++;
		}
		else if ((expr1[ind] == '+') || (expr1[ind] == '-'))
		{ // �������������� �������� � ������ �����������
			if (Temp->size == 0)
			{
				push(Temp, GetCharP(expr1[ind]));
				ind++;
			}
			else if (*(char*)Temp->head->value == '(')
			{
				push(Temp, GetCharP(expr1[ind]));
				ind++;
			}
			else
			{
				ch = (char*)pop(Temp);
				expr2[ind2] = ch[0];
				ind2++;
			}
		}
		else if ((expr1[ind] == '*') || (expr1[ind] == '/'))
		{ // �������������� �������� � ������� �����������
			if (Temp->size == 0)
			{
				push(Temp, GetCharP(expr1[ind]));
				ind++;
			}
			else
			{
				ch = (char*)Temp->head->value;
				if ((ch[0] == '+') || (ch[0] == '-') || (ch[0] == '('))
				{
					push(Temp, GetCharP(expr1[ind]));
					ind++;
				}
				else
				{
					ch = (char*)pop(Temp);
					expr2[ind2] = ch[0];
					ind2++;
				}
			}
		}
		else if (expr1[ind] == '(')
		{ // ����������� ������
			push(Temp, GetCharP(expr1[ind]));
			ind++;
		}
		else if (expr1[ind] == ')')
		{	// ����������� ������
			if (Temp->size == 0)
			{
				error = -1;
				break;
			}
			else
			{
				ch = (char*)pop(Temp);
				if (ch[0] != '(')
				{
					expr2[ind2] = ch[0];
					ind2++;
				}
				else
				{
					ind++;
				}
			}
		}
		else if (expr1[ind] == '\0')
		{ // ������� ������ �����������
			ch = (char*)pop(Temp);
			if (ch[0] == '(')
			{
				error = -1;
				break;
			}
			else
			{
				expr2[ind2] = ch[0];
				ind2++;
			}
		}
	}

	expr2[ind2] = '\0';

	if (error == 0)
	{
		printf("��������� � ����������� ������: %s\n", expr2);
	}
	else
	{
		printf("\n��������� �� ��������������!\n");
	}

	Erase(Temp);
	free(Temp);
	
	pause();
}

// 5. ����������� �������:
//   1. � �������������� �������.
//   2. *� �������������� ������������ ������.
//
// === � �������������� ������� ===

#define maxQ 10

struct TQueue1
{
	int tail;
	int data[maxQ];
};

typedef struct TQueue1 TQueue1;

int pushQ1(TQueue1* queue, int value)
{
	if ((*queue).tail < maxQ - 1)
	{
		for (int i = (*queue).tail; i >= 0; i--)
		{
			(*queue).data[i + 1] = (*queue).data[i];
		}
		(*queue).tail++;
		(*queue).data[0] = value;
		return 0;
	}
	else
	{
		return -1;
	}
}

int popQ1(TQueue1* queue, int* value)
{
	if ((*queue).tail >= 0)
	{
		(*queue).tail--;
		*value = (*queue).data[(*queue).tail + 1];
	}
	else
	{
		return -1;
	}
}

// === � �������������� ������������ ������

struct TNodeQ2
{
	int value;
	struct TNodeQ2* next;
};

typedef struct TNodeQ2 TNodeQ2;

struct TQueue2
{
	TNodeQ2* head;
	int size;
	int maxSize;
};

typedef struct TQueue2 TQueue2;

// ���
int pushQ2(TQueue2* queue, int value)
{
	if (queue->size >= queue->maxSize)
	{
		return -1;
	}
	TNodeQ2* tmp = (TNodeQ2*)malloc(sizeof(TNodeQ2));
	tmp->value = value;
	tmp->next = queue->head;
	queue->head = tmp;
	queue->size++;
	return 0;
}

// ���
int popQ2(TQueue2* queue, int* value)
{
	if (queue->size == 0)
	{
		return -1;
	}
	else
	{
		queue->size--;

		TNodeQ2* current;
		current = queue->head;

		if (current->next == NULL)
		{
			*value = current->value;
			free(current);
			queue->head = NULL;
		}
		else
		{
			while (current->next->next != NULL)
			{
				current = current->next;
			}
			*value = current->next->value;
			free(current->next);
			current->next = NULL;
		}
		return 0;
	}
}

// ������� ������� (�� �� ��������!)
void EraseQ2(TQueue2* queue)
{
	TNodeQ2* current = queue->head;
	TNodeQ2* next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	queue->head = NULL;
	queue->size = 0;
}

// ������������� ����� �������
void InitQ2(TQueue2* queue, int maxSize)
{
	queue->maxSize = maxSize;
	queue->size = 0;
	queue->head = NULL;
}

void task05()
{
	printf("������ 05 (���������� �������)\n\n");

	printf("� �������������� �������\n");

	TQueue1 queue1;
	queue1.tail = -1;

	int value;
	srand(time(NULL));

	printf(" - � �������: ");
	// ���������� ������� ���������� �������
	for (int i = 0; i < 10; i++)
	{
		value = rand() % 100;
		pushQ1(&queue1, value);
		if (i != 9)
			printf("%d, ", value);
		else
			printf("%d.\n", value);
	}
	printf(" - �� �������: ");
	// ���������� ������ �� �������
	while (queue1.tail != -1)
	{
		popQ1(&queue1, &value);
		if (queue1.tail != -1)
			printf("%d, ", value);
		else
			printf("%d.\n\n", value);
	}

	printf("� ��������������� ������������ ������\n");

	TQueue2 queue2;
	InitQ2(&queue2, 10);
	
	printf(" - � �������: ");
	// ���������� ������� ���������� �������
	for (int i = 0; i < 10; i++)
	{
		value = rand() % 100;
		pushQ2(&queue2, value);
		if (i != 9)
			printf("%d, ", value);
		else
			printf("%d.\n", value);
	}
	printf(" - �� �������: ");
	// ���������� ������ �� �������
	while (queue2.size != 0)
	{
		popQ2(&queue2, &value);
		if (queue2.size != 0)
			printf("%d, ", value);
		else
			printf("%d.\n\n", value);
	}

	pause();
}

// 6. ***����������� ������������ �������.
//
void task06()
{
	printf("������ 06 (������������ �������)\n\n");

	pause();
}
