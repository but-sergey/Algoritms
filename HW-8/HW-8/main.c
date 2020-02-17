// ================================================================
// ��������!!! ��� ����������� ������� ���� (� Win7) � ���� �������
// � ��������� �������� ����� �� Lucida Console!
// ================================================================

// ���� "��������� � ��������� ������"
// ������������ ������ �8
// ��� ������

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#pragma warning(disable:6031)

// ������ �������
#define MaxInd 100
#define MaxN 100

void menu();
void task01();
void task02();
void task03();

int main(int argc, const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

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
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	system("cls");
	printf(" 1 - ������ 01 (���������� ���������)\n");
	printf(" 2 - ������ 02 (������� ����������)\n");
	printf(" 3 - ������ 03 (���������� ��������)\n");
	printf(" 0 - �����\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\n������� <Enter> ��� �����������...");
	getch();
}

// ����� �������� ���� ����������
void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// ����� ������� �� �����
void PrintArray(int* a, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}

// ���������� ������� ���������� ������� �� 0 �� 99
void FillRandom(int* a, int N)
{
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
}

// 1. ����������� ���������� ���������
//
void CountingSort(int* a, int N)
{
	// �������� ������ � �������� ��������� ������
	int* C = (int*)malloc(MaxN * sizeof(int));
	for (int i = 0; i < MaxN; i++)
	{
		C[i] = 0;
	}

	// ������������ ���������� ��������� ������� �������� ��������� �������
	for (int i = 0; i < N; i++)
	{
		C[a[i]]++;
	}

	// �������������� �������� ������ � ������������� ���������� �������
	int ind = 0;
	for (int i = 0; i < MaxN; i++)
	{
		for (int j = 0; j < C[i]; j++)
		{
			a[ind] = i;
			ind++;
		}
	}

	free(C);
}

void task01()
{
	printf("������ 01 (���������� ���������)\n\n");

	// ������������� �������
	int a[MaxInd];
	FillRandom(&a, MaxInd);

	// ����� ������� �� ����������
	printf("������ �� ����������:\n");
	PrintArray(&a, MaxInd);

	// ����������
	CountingSort(&a, MaxInd);

	// ����� ������� ����� ����������
	printf("\n������ ����� ���������� ���������:\n");
	PrintArray(&a, MaxInd);

	pause();
}

// 2. ����������� ������� ����������.
//
void QuickSort(int* a, int first, int last)
{
	int i = first;
	int j = last;
	int x = a[(first + last) / 2];

	do
	{
		// ������� ������ ������� � ������ �������, ������� �� ����� ��������
		while (a[i] < x)
			i++;
		
		// ������� ������ ������� � ����� �������, ������� �� ����� ��������
		while (a[j] > x)
			j--;
		
		// ���� ��� �� ���� � ��� �� �������, �� ������ �������
		if (i <= j)
		{
			if (a[i] > a[j])
				Swap(&a[i], &a[j]);
			i++;
			j--;
		}
	} while (i <= j);

	// ��������� ���������� ����� �������: �� �������� � ����� �������� ��������
	if (i < last)
		QuickSort(a, i, last);
	if (first < j)
		QuickSort(a, first, j);
}

void task02()
{
	printf("������ 02 (������� ����������)\n\n");

	// ������������� �������
	int a[MaxInd];
	FillRandom(&a, MaxInd);

	// ����� ������� �� ����������
	printf("������ �� ����������:\n");
	PrintArray(&a, MaxInd);

	// ����������
	QuickSort(&a, 0, MaxInd - 1);

	// ����� ������� ����� ����������
	printf("\n������ ����� ������� ���������� (���������� �����):\n");
	PrintArray(&a, MaxInd);

	pause();
}

// 3. *����������� ���������� ��������.
//
void Merge(int* a, int first, int last)
{
	// ��������� ������ ��� �������
	int* tmp = (int*)malloc((last - first + 1) * sizeof(int));
	int ind = 0;

	// ������� ����������
	int r = (first + last) / 2;

	// ������ � ������ ���������
	int f = first;
	// ������ �� ������ ���������
	int l = r + 1;

	// ����������, �������
	while ((f <= r) || (l <= last))
	{
		// ���� ������ ������� ��������� ����� �� �������, �� �������� � ������ ������ ��������
		if (f > r)
		{
			tmp[ind] = a[l];
			l++;
		}
		// ���� ������ ������� ��������� ����� �� �������, �� �������� � ������ ������ ��������
		else if (l > last)
		{
			tmp[ind] = a[f];
			f++;
		}
		// ���� ������� ��� ������ ����������
		else
		{
			// �������� � ������ ������� �������
			if (a[f] < a[l])
			{
				tmp[ind] = a[f];
				f++;
			}
			else if (a[f] > a[l])
			{
				tmp[ind] = a[l];
				l++;
			}
			// ���� �������� �����, �� �������� ���
			else
			{
				tmp[ind] = a[f];
				tmp[ind + 1] = a[l];
				f++;
				l++;
				ind++;
			}
		}
		ind++;
	}
	// ����������� ���������� ������� � ��������
	ind = 0;
	for (int i = first; i <= last; i++)
	{
		a[i] = tmp[ind];
		ind++;
	}
	free(tmp);
}

void MergeSort(int* a, int first, int last)
{
	// �������� ������� �� ����� ��� 1 ��������
	if (first < last)
	{
		// �������� ������� �� 2� ���������
		if (last - first == 1)
		{
			if (a[first] > a[last])
				Swap(&a[first], &a[last]);
		}
		else
		{
			// ��������� ����� �������� ���������
			MergeSort(a, first, (first + last) / 2);
			// ��������� ������ �������� ���������
			MergeSort(a, (first + last) / 2 + 1, last);
			// ������� ���������
			Merge(a, first, last);
		}
		
	}
}

void task03()
{
	printf("������ 03 (���������� ��������)\n\n");

	// ������������� �������
	int a[MaxInd];
	FillRandom(&a, MaxInd);

	// ����� ������� �� ����������
	printf("������ �� ����������:\n");
	PrintArray(&a, MaxInd);

	// ����������
	MergeSort(&a, 0, MaxInd - 1);

	// ����� ������� ����� ����������
	printf("\n������ ����� ���������� ��������:\n");
	PrintArray(&a, MaxInd);

	pause();
}
