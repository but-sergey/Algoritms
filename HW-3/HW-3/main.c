// ================================================================
// ��������!!! ��� ����������� ������� ���� (� Win7) � ���� �������
// � ��������� �������� ����� �� Lucida Console!
// ================================================================

// ���� "��������� � ��������� ������"
// ������������ ������ �3
// ��� ������

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#pragma warning(disable:6031)

#define MaxN 100

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
		case 4: task04();
			break;
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	system("cls");
	printf(" 1 - ������ 01 (����������� ����������� ����������)\n");
	printf(" 2 - ������ 02 (��������� ����������)\n");
	printf(" 3 - ������ 03 (�������� �����)\n");
	printf(" 4 - ������ 04 (������ ��������� ���������)\n\n");
	printf(" 0 - �����\n");
	printf(" -=> ");
}

void pause()
{
	printf("\n������� <Enter> ��� �����������...");
	getch();
}

void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void print(int N, int* a)
{
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
}

// 1. ����������� �������������� ����������� ����������. �������� ���������� ��������
// ��������� ���������������� � �� ���������������� ���������. �������� ������� ����������,
// ������� ���������� ���������� ��������.
//
void Sort1(int N, int* a, int* c_if, int* c_swap)
{
	*c_if = 0;
	*c_swap = 0;

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N - 1; j++)
		{
			*c_if += 1;
			if (a[j] > a[j + 1])
			{
				*c_swap += 1;
				swap(&a[j], &a[j + 1]);
			}
		}

}

int Sort2(int N, int* a, int* c_if, int* c_swap)
{
	*c_if = 0;
	*c_swap = 0;

	for (int i = 0; i < N; i++)
		// ��� ������ ������������� ��� ��������������� �������, � ���������
		for (int j = 0; j < N - i - 1; j++)
		{
			*c_if += 1;
			if (a[j] > a[j + 1])
			{
				*c_swap += 1;
				swap(&a[j], &a[j + 1]);
			}
		}
}

void task01()
{
	printf("������ 01 (����������� ����������� ����������)\n\n");
	
	srand(time(NULL));
	int a[MaxN];
	int b[MaxN];
	int c_if;
	int c_swap;
	
	// ���������� ���� ���������� �������� ��� ��������� ����������
	for (int i = 0; i < MaxN; i++)
	{
		a[i] = rand() % 100;
		b[i] = a[i];
	}

	printf("������ �� ����������: ");
	print(MaxN, a);

	Sort1(MaxN, a, &c_if, &c_swap);
	printf("������ ����� ������� ���������� (%d �������� ���������, %d �������): ", c_if, c_swap);
	print(MaxN, a);

	Sort2(MaxN, b, &c_if, &c_swap);
	printf("������ ����� ���������������� ���������� (%d �������� ���������, %d �������): ", c_if, c_swap);
	print(MaxN, b);
	
	pause();
}

// 2. *����������� ��������� ����������.
//
// === � ��� ������ ��������� ���������� �� ������ �������, ���������� ���������-������� ����-�-���� � �����������

void Sort3(int N, int* a, int* c_if, int* c_swap)
{
	*c_if = 0;
	*c_swap = 0;

	for (int i = 0; i < (N + 1) / 2; i++)
	{
		// ������ "����"
		for (int j = i; j < N - i - 1; j++)
		{
			*c_if += 1;
			if (a[j] > a[j + 1])
			{
				*c_swap += 1;
				swap(&a[j], &a[j + 1]);
			}
		}
		// ������ "�������"
		for (int j = N - i - 3; j >= i; j--)
		{
			*c_if += 1;
			if (a[j] > a[j + 1])
			{
				*c_swap += 1;
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}

void task02()
{
	printf("������ 02 (��������� ����������)\n\n");

	srand(time(NULL));
	int a[MaxN];
	int b[MaxN];
	int c_if;
	int c_swap;

	// ���������� ���� ���������� �������� ��� ��������� ����������
	for (int i = 0; i < MaxN; i++)
	{
		a[i] = rand() % 100;
		b[i] = a[i];
	}

	//printf("������ �� ����������: ");
	//print(MaxN, a);

	Sort2(MaxN, a, &c_if, &c_swap);
	printf("������ ����� ���������������� ����������� ����������\n(%d �������� ���������, %d �������, %d �����): ", c_if, c_swap, c_if + c_swap);
	print(MaxN, a);

	Sort3(MaxN, b, &c_if, &c_swap);
	printf("������ ����� ��������� ����������\n(%d �������� ���������, %d �������, %d �����): ", c_if, c_swap, c_if + c_swap);
	print(MaxN, b);
	
	pause();
}

// 3. ����������� �������� �������� ������ � ���� �������, ������� ���������� ���������������
// ������. ������� ���������� ������ ���������� �������� ��� - 1, ���� ������� �� ������.
//
void task03()
{
	printf("������ 03 (�������� �����)\n\n");

	pause();
}

// 4. *���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ���������������
// ���������� ���������.
//
void task04()
{
	printf("������ 04 (������ ��������� ���������)\n\n");

	pause();
}

// 5. ** ����������� ���������� ���������, ��������� �������� �����.
