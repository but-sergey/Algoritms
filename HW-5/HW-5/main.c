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

#define T short

struct TNode
{
	T value;
	struct TNode* next;
};

typedef struct TNode Node;

struct Stack
{
	Node* head;
	int size;
	int maxSize;
};

struct Stack Stack;

int push(T value)
{
	if (Stack.size >= Stack.maxSize)
	{
		return -1;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
	return 0;
}

T pop()
{
	if (Stack.size == 0)
	{
		return NULL;
	}
	Node* next = NULL;
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	free(next);
	Stack.size--;
	return value;
}

void PrintStack()
{
	Node* current = Stack.head;
	while (current != NULL)
	{
		printf("%d", current->value);
		current = current->next;
	}
}

void EraseStack()
{
	Node* current = Stack.head;
	Node* next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	Stack.head = NULL;
	Stack.size = 0;
}

void task01()
{	
	printf("������ 01 (������� �� ���������� � �������� �������)\n\n");
	
	int num;
	Stack.maxSize = 100;

	printf("����� � ���������� �������: ");
	scanf("%d", &num);
	while (num != 0)
	{
		if (push(num % 2) == 0)
		{
			num /= 2;
		}
		else
		{
			printf("������������ �����/n");
		}
	}
	printf("����� � �������� �������: ");
	PrintStack();
	EraseStack();
	printf("\n");

	pause();
}

// 2. �������� ���������, ������� ����������, �������� �� ��������� ���������
// ������������������ ����������.������� ���������� ��������� ��������� : (), ([])(), {}(),
// ([{}]), ������������ � )(, ())({ ), (, ]) }), ([(]) ��� ������[, (, { .
// ��������: (2 + (2 * 2)) ���[2 / {5 * (4 + 7)}].
//
void task02()
{
	printf("������ 02 (��������� ������������������)\n\n");

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
