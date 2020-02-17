// ================================================================
// Внимание!!! Для отображения русских букв (в Win7) в окне консоли
// в свойствах изменить шрифт на Lucida Console!
// ================================================================

// Курс "Алгоритмы и структуры данных"
// Практическая работа №8
// Бут Сергей

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#pragma warning(disable:6031)

// размер массива
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
	printf(" 1 - Задача 01 (сортировка подсчетом)\n");
	printf(" 2 - Задача 02 (быстрая сортировка)\n");
	printf(" 3 - Задача 03 (сортировка слиянием)\n");
	printf(" 0 - выход\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\nНажмите <Enter> для продолжения...");
	getch();
}

// обмен значений двух переменных
void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// вывод массива на экран
void PrintArray(int* a, int N)
{
	for (int i = 0; i < N; i++)
	{
		printf("%3d", a[i]);
	}
	printf("\n");
}

// Заполнение массива случайными числами от 0 до 99
void FillRandom(int* a, int N)
{
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 100;
	}
}

// 1. Реализовать сортировку подсчетом
//
void CountingSort(int* a, int N)
{
	// выделяем память и обнуляем частотный массив
	int* C = (int*)malloc(MaxN * sizeof(int));
	for (int i = 0; i < MaxN; i++)
	{
		C[i] = 0;
	}

	// подсчитываем количество вхождений каждого элемента исходного массива
	for (int i = 0; i < N; i++)
	{
		C[a[i]]++;
	}

	// перезаписываем исходный массив с исползованием частотного массива
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
	printf("Задача 01 (сортировка подсчетом)\n\n");

	// инициализация массива
	int a[MaxInd];
	FillRandom(&a, MaxInd);

	// вывод массива до сортировки
	printf("Массив до сортировки:\n");
	PrintArray(&a, MaxInd);

	// сортировка
	CountingSort(&a, MaxInd);

	// вывод массива после сортировки
	printf("\nМассив после сортировки подсчетом:\n");
	PrintArray(&a, MaxInd);

	pause();
}

// 2. Реализовать быструю сортировку.
//
void QuickSort(int* a, int first, int last)
{
	int i = first;
	int j = last;
	int x = a[(first + last) / 2];

	do
	{
		// находим первый элемент с начала массива, который не менее опорного
		while (a[i] < x)
			i++;
		
		// находим первый элемент с конца массива, который не более опорного
		while (a[j] > x)
			j--;
		
		// если это не один и тот же элемент, то меняем местами
		if (i <= j)
		{
			if (a[i] > a[j])
				Swap(&a[i], &a[j]);
			i++;
			j--;
		}
	} while (i <= j);

	// сортируем оставшиеся части массива: до опорного и после опорного элемента
	if (i < last)
		QuickSort(a, i, last);
	if (first < j)
		QuickSort(a, first, j);
}

void task02()
{
	printf("Задача 02 (быстрая сортировка)\n\n");

	// инициализация массива
	int a[MaxInd];
	FillRandom(&a, MaxInd);

	// вывод массива до сортировки
	printf("Массив до сортировки:\n");
	PrintArray(&a, MaxInd);

	// сортировка
	QuickSort(&a, 0, MaxInd - 1);

	// вывод массива после сортировки
	printf("\nМассив после быстрой сортировки (сортировки Хоара):\n");
	PrintArray(&a, MaxInd);

	pause();
}

// 3. *Реализовать сортировку слиянием.
//
void Merge(int* a, int first, int last)
{
	// временный массив для слияния
	int* tmp = (int*)malloc((last - first + 1) * sizeof(int));
	int ind = 0;

	// граница фрагментов
	int r = (first + last) / 2;

	// индекс в первом фрагменте
	int f = first;
	// индекс во втором фрагменте
	int l = r + 1;

	// собственно, слияние
	while ((f <= r) || (l <= last))
	{
		// если индекс первого фрагмента вышел за границу, то копируем в массив второй фрагмент
		if (f > r)
		{
			tmp[ind] = a[l];
			l++;
		}
		// если индекс второго фрагмента вышел за границу, то копируем в массив первый фрагмент
		else if (l > last)
		{
			tmp[ind] = a[f];
			f++;
		}
		// если индексы ещё внутри фрагментов
		else
		{
			// копируем в массив меньший элемент
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
			// если элементы равны, то копируем оба
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
	// копирование временного массива в исходный
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
	// фрагмент состоит из более чем 1 элемента
	if (first < last)
	{
		// фрагмент состоит из 2х элементов
		if (last - first == 1)
		{
			if (a[first] > a[last])
				Swap(&a[first], &a[last]);
		}
		else
		{
			// сортируем левую половину фрагмента
			MergeSort(a, first, (first + last) / 2);
			// сортируем правую половину фрагмента
			MergeSort(a, (first + last) / 2 + 1, last);
			// сливаем фрагменты
			Merge(a, first, last);
		}
		
	}
}

void task03()
{
	printf("Задача 03 (сортировка слиянием)\n\n");

	// инициализация массива
	int a[MaxInd];
	FillRandom(&a, MaxInd);

	// вывод массива до сортировки
	printf("Массив до сортировки:\n");
	PrintArray(&a, MaxInd);

	// сортировка
	MergeSort(&a, 0, MaxInd - 1);

	// вывод массива после сортировки
	printf("\nМассив после сортировки слиянием:\n");
	PrintArray(&a, MaxInd);

	pause();
}
