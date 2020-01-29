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
	printf(" 3 - ������ 04 (������� �� ��������� ������ � �����������)\n");
	printf(" 3 - ������ 05 (���������� �������)\n");
	printf(" 3 - ������ 06 (������������ �������)\n\n");
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
void task03()
{
	printf("������ 03 (����������� ������������ ������)\n\n");

	pause();
}

// 4. *����������� �������� �������� �� ��������� ������ ��������������� ��������� �
// �����������
//
void task04()
{
	printf("������ 04 (������� �� ��������� ������ � �����������)\n\n");

	pause();
}

// 5. ����������� �������:
//   1. � �������������� �������.
//   2. *� �������������� ������������ ������.
//
void task05()
{
	printf("������ 05 (���������� �������)\n\n");

	pause();
}

// 6. ***����������� ������������ �������.
//
void task06()
{
	printf("������ 06 (������������ �������)\n\n");

	pause();
}
