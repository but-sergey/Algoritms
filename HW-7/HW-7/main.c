// ================================================================
// ��������!!! ��� ����������� ������� ���� (� Win7) � ���� �������
// � ��������� �������� ����� �� Lucida Console!
// ================================================================

// ���� "��������� � ��������� ������"
// ������������ ������ �7
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
//		case 4: task04();
//			break;
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	system("cls");
	printf(" 1 - ������ 01 (������� ���������)\n");
	printf(" 2 - ������ 02 (����� ����� � �������)\n");
	printf(" 3 - ������ 03 (����� ����� � ������)\n");
	//printf(" 4 - ������ 04 (���������� ������� ��� ������ � �������)\n\n");
	printf(" 0 - �����\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\n������� <Enter> ��� �����������...");
	getch();
}

// 1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����
//

int** ReadMatrix(char* fileName, int* N)
{
	// ���������� ���������� �����
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("���� �� ������!\n");
		return NULL;
	}
	
	// ������ �� ����� ������� �������
	fscanf(file, "%d", N);
	
	// �������������� ������ ��� �������
	int** Matrix = (int**)malloc(*N * sizeof(int*));
	for (int i = 0; i < *N; i++)
	{
		Matrix[i] = (int*)malloc(*N * sizeof(int));
	}

	// ������ ������� �� �����
	for (int i = 0; i < *N; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			fscanf(file, "%d", &Matrix[i][j]);
		}
	}

	return Matrix;
}

void PrintMatrix(int** Matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%4d ", Matrix[i][j]);
		}
		printf("\n");
	}
}

void FreeMatrix(int** Matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		free(Matrix[i]);
	}
	free(Matrix);
	Matrix = NULL;
}

void task01()
{
	printf("������ 01 (������� ���������)\n\n");

	int N;
	int** Matrix = ReadMatrix("..\\matrix.txt", &N);

	PrintMatrix(Matrix, N);

	FreeMatrix(Matrix, N);

	pause();
}

// 2. �������� ����������� ������� ������ ����� � �������.
//
// ������� ��� ����� - 1 ��� ����������� ��� �� ������������ ������
// � 2 ��� ����������� ��� ������������

// === ���������� �����
struct TNode
{
	int value;
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

int push(TStack* Stack, int value)
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

int* pop(TStack* Stack)
{
	if (Stack->size == 0)
	{
		return NULL;
	}
	TNode* tmp = NULL;
	int* value = (int*)malloc(sizeof(int));
	*value = Stack->head->value;
	tmp = Stack->head;
	Stack->head = Stack->head->next;
	free(tmp);
	Stack->size--;
	return value;
}
// === ����� ���������� �����

void DeepTraverse(TStack* processed, int** Matrix, int node, int N)
{
	TNode* current = processed->head;
	BOOL flag = FALSE;
	while (current != NULL)
	{
		if (current->value == node)
		{
			flag = TRUE;
			break;
		}
		current = current->next;
	}

	// ���� ������� ��� �� ����������...
	if (!flag)
	{
		printf("%d ", node);
		push(processed, node);
		for (int i = 0; i < N; i++)
		{
			if (Matrix[node][i] != 0)
			{
				DeepTraverse(processed, Matrix, i, N);
			}
		}
	}
}

void task02()
{
	printf("������ 02 (����� ����� � �������)\n\n");

	// ������ �����
	int N;
	int** Matrix = ReadMatrix("..\\matrix.txt", &N);

	PrintMatrix(Matrix, N);
	printf("\n");

	TStack processed;
	processed.head = NULL;
	processed.size = 0;
	processed.maxSize = 100;

	// ����� � �������
	printf("����� \"����� � �������\": ");
	DeepTraverse(&processed, Matrix, 0, N);
	printf("\n");

	// ������������ ������
	FreeMatrix(Matrix, N);

	pause();
}

// 3. �������� ������� ������ ����� � ������
//
void task03()
{
	printf("������ 03 (����� ����� � ������)\n\n");

	// ������ �����
	int N;
	int** Matrix = ReadMatrix("..\\matrix.txt", &N);

	PrintMatrix(Matrix, N);



	// ������������ ������
	FreeMatrix(Matrix, N);

	pause();
}

// 4. *������� ���������� ������� ��� ������ � �������.
//
void task04()
{
	printf("������ 04 (���������� ������� ��� ������ � �������)\n\n");

	pause();
}
