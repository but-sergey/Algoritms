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
	for (int i = 0; i < N; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");
}

void fillRandom(int N, int* a)
{
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % MaxN;
	}
}

void copyArray(int N, int* a, int* b)
{
	for (int i = 0; i < N; i++)
	{
		b[i] = a[i];
	}
}

// 1. ����������� �������������� ����������� ����������. �������� ���������� ��������
// ��������� ���������������� � �� ���������������� ���������. �������� ������� ����������,
// ������� ���������� ���������� ��������.
//
void Sort1(int N, int* a, int* c_if, int* c_swap)
{
	if (c_if != NULL) { *c_if = 0; }
	if (c_swap != NULL) { *c_swap = 0; }

	for(int i = 0; i < N; i++)
		for (int j = 0; j < N - 1; j++)
		{
			if (c_if != NULL) { *c_if += 1; }
			if (a[j] > a[j + 1])
			{
				if (c_swap != NULL) { *c_swap += 1; }
				swap(&a[j], &a[j + 1]);
			}
		}

}

int Sort2(int N, int* a, int* c_if, int* c_swap)
{
	if (c_if != NULL) { *c_if = 0; }
	if (c_swap != NULL) { *c_swap = 0; }

	for (int i = 0; i < N; i++)
		// ��� ������ ������������� ��� ��������������� �������, � ���������
		for (int j = 0; j < N - i - 1; j++)
		{
			if (c_if != NULL) { *c_if += 1; }
			if (a[j] > a[j + 1])
			{
				if (c_swap != NULL) { *c_swap += 1; }
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
	fillRandom(MaxN, &a);
	copyArray(MaxN, &a, &b);

	printf("������ �� ����������:\n");
	print(MaxN, a);

	Sort1(MaxN, a, &c_if, &c_swap);
	printf("������ ����� ������� ���������� (%d �������� ���������, %d �������):\n", c_if, c_swap);
	print(MaxN, a);

	Sort2(MaxN, b, &c_if, &c_swap);
	printf("������ ����� ���������������� ���������� (%d �������� ���������, %d �������):\n", c_if, c_swap);
	print(MaxN, b);
	
	pause();
}

// 2. *����������� ��������� ����������.
//
// === � ��� ������ ��������� ���������� �� ������ �������, ���������� ���������-������� ����-�-���� � �����������

void Sort3(int N, int* a, int* c_if, int* c_swap)
{
	if (c_if != NULL) { *c_if = 0; }
	if (c_swap != NULL) { *c_swap = 0; }

	for (int i = 0; i < (N + 1) / 2; i++)
	{
		// ������ "����"
		for (int j = i; j < N - i - 1; j++)
		{
			if (c_if != NULL) { *c_if += 1; }
			if (a[j] > a[j + 1])
			{
				if (c_swap != NULL) { *c_swap += 1; }
				swap(&a[j], &a[j + 1]);
			}
		}
		// ������ "�������"
		for (int j = N - i - 3; j >= i; j--)
		{
			if (c_if != NULL) { *c_if += 1; }
			if (a[j] > a[j + 1])
			{
				if (c_swap != NULL) { *c_swap += 1; }
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
	fillRandom(MaxN, &a);
	copyArray(MaxN, &a, &b);

	printf("������ �� ����������:\n");
	print(MaxN, a);

	Sort2(MaxN, a, &c_if, &c_swap);
	printf("������ ����� ���������������� ����������� ����������\n(%d �������� ���������, %d �������, %d �����):\n", c_if, c_swap, c_if + c_swap);
	print(MaxN, a);

	Sort3(MaxN, b, &c_if, &c_swap);
	printf("������ ����� ��������� ����������\n(%d �������� ���������, %d �������, %d �����):\n", c_if, c_swap, c_if + c_swap);
	print(MaxN, b);
	
	pause();
}

// 3. ����������� �������� �������� ������ � ���� �������, ������� ���������� ���������������
// ������. ������� ���������� ������ ���������� �������� ��� - 1, ���� ������� �� ������.
//

int findBin(int N, int* a, int num)
{
	int result = -1;
	int min = 0;
	int max = N - 1;
	int ind = min + (max - min) / 2;

	while (min!=max)
	{
		ind = min + (max - min) / 2;
		if (a[ind] == num)
		{
			result = ind;
			break;
		}
		else if (a[ind] > num)
		{
			max = ind - 1;
		}
		else
		{
			min = ind + 1;
		}
	}
	if (a[min] == num)
	{
		result = min;
	}


	return result;
}

void task03()
{
	printf("������ 03 (�������� �����)\n\n");

	int a[MaxN];
	int num;
	int ind;
	
	// ���������� ������� ���������� ����������
	fillRandom(MaxN, &a);

	// ���������� (������� ����� �� �����)
	Sort3(MaxN, &a, NULL, NULL);

	printf("�������� ������:\n");
	print(MaxN, &a);

	// ���� �������� ��� ������
	printf("������� ��� ������: ");
	scanf("%d", &num);

	// �����
	ind = findBin(MaxN, &a, num);

	if (ind == -1)
	{
		printf("������� ������� %d �� ������.\n", num);
	}
	else
	{
		printf("������� ������� %d ����� ������ %d.\n", num, ind);
	}

	pause();
}

// 4. *���������� ���������� �������� ��� ������ �� ���������� � �������� ��� � ���������������
// ���������� ���������.
//
void task04()
{
	int a[MaxN];
	int b[MaxN];
	int c[MaxN];
	int c_if;
	int c_swap;

	fillRandom(MaxN, &a);
	copyArray(MaxN, &a, &b);
	copyArray(MaxN, &a, &c);

	printf("������ 04 (������ ��������� ���������)\n\n");

	printf("��������������� ��������� ����������� ���������� O(N^2)\n");
	printf("��� N=%d ��������� O(N^2) = %d\n\n", MaxN, MaxN*MaxN);
	printf("� ����� ������ ���������� ��������:\n");
	Sort1(MaxN, &a, &c_if, &c_swap);
	printf("������������ ��������: %d\n", c_if + c_swap);
	Sort2(MaxN, &b, &c_if, &c_swap);
	printf("���������������� ��������: %d\n", c_if + c_swap);
	Sort3(MaxN, &c, &c_if, &c_swap);
	printf("��������� ����������: %d\n", c_if + c_swap);

	pause();
}

// 5. ** ����������� ���������� ���������, ��������� �������� �����.
