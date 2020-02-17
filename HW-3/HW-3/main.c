// ================================================================
// Внимание!!! Для отображения русских букв (в Win7) в окне консоли
// в свойствах изменить шрифт на Lucida Console!
// ================================================================

// Курс "Алгоритмы и структуры данных"
// Практическая работа №3
// Бут Сергей

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
	printf(" 1 - Задача 01 (оптимизация пузырьковой сортировки)\n");
	printf(" 2 - Задача 02 (шейкерная сортировка)\n");
	printf(" 3 - Задача 03 (бинарный поиск)\n");
	printf(" 4 - Задача 04 (расчет сложности алгоритма)\n\n");
	printf(" 0 - выход\n");
	printf(" -=> ");
}

void pause()
{
	printf("\nНажмите <Enter> для продолжения...");
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

// 1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций
// сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки,
// которые возвращают количество операций.
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
		// нет смысла просматривать уже отсортированную область, её исключаем
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
	printf("Задача 01 (оптимизация пузырьковой сортировки)\n\n");
	
	srand(time(NULL));
	int a[MaxN];
	int b[MaxN];
	int c_if;
	int c_swap;
	
	// заполнение двух одинаковых массивов для сравнения алгоритмов
	fillRandom(MaxN, &a);
	copyArray(MaxN, &a, &b);

	printf("Массив до сортировки:\n");
	print(MaxN, a);

	Sort1(MaxN, a, &c_if, &c_swap);
	printf("Массив после обычной сортировки (%d операций сравнения, %d обменов):\n", c_if, c_swap);
	print(MaxN, a);

	Sort2(MaxN, b, &c_if, &c_swap);
	printf("Массив после оптимизированной сортировки (%d операций сравнения, %d обменов):\n", c_if, c_swap);
	print(MaxN, b);
	
	pause();
}

// 2. *Реализовать шейкерную сортировку.
//
// === В чем профит шейкерной сортировки не совсем понятно, количество сравнений-обменов один-в-один с пузырьковой

void Sort3(int N, int* a, int* c_if, int* c_swap)
{
	if (c_if != NULL) { *c_if = 0; }
	if (c_swap != NULL) { *c_swap = 0; }

	for (int i = 0; i < (N + 1) / 2; i++)
	{
		// проход "туда"
		for (int j = i; j < N - i - 1; j++)
		{
			if (c_if != NULL) { *c_if += 1; }
			if (a[j] > a[j + 1])
			{
				if (c_swap != NULL) { *c_swap += 1; }
				swap(&a[j], &a[j + 1]);
			}
		}
		// проход "обратно"
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
	printf("Задача 02 (шейкерная сортировка)\n\n");

	srand(time(NULL));
	int a[MaxN];
	int b[MaxN];
	int c_if;
	int c_swap;

	// заполнение двух одинаковых массивов для сравнения алгоритмов
	fillRandom(MaxN, &a);
	copyArray(MaxN, &a, &b);

	printf("Массив до сортировки:\n");
	print(MaxN, a);

	Sort2(MaxN, a, &c_if, &c_swap);
	printf("Массив после оптимизированной пузырьковой сортировки\n(%d операций сравнения, %d обменов, %d всего):\n", c_if, c_swap, c_if + c_swap);
	print(MaxN, a);

	Sort3(MaxN, b, &c_if, &c_swap);
	printf("Массив после шейкерной сортировки\n(%d операций сравнения, %d обменов, %d всего):\n", c_if, c_swap, c_if + c_swap);
	print(MaxN, b);
	
	pause();
}

// 3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный
// массив. Функция возвращает индекс найденного элемента или - 1, если элемент не найден.
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
	printf("Задача 03 (бинарный поиск)\n\n");

	int a[MaxN];
	int num;
	int ind;
	
	// заполнение массива случайными значениями
	fillRandom(MaxN, &a);

	// сортировка (подсчет шагов не нужен)
	Sort3(MaxN, &a, NULL, NULL);

	printf("Исходный массив:\n");
	print(MaxN, &a);

	// ввод элемента для поиска
	printf("Элемент для поиска: ");
	scanf("%d", &num);

	// поиск
	ind = findBin(MaxN, &a, num);

	if (ind == -1)
	{
		printf("Искомый элемент %d не найден.\n", num);
	}
	else
	{
		printf("Искомый элемент %d имеет индекс %d.\n", num, ind);
	}

	pause();
}

// 4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической
// сложностью алгоритма.
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

	printf("Задача 04 (расчет сложности алгоритма)\n\n");

	printf("Асимптотическая сложность пузырьковой сортировки O(N^2)\n");
	printf("Для N=%d сложность O(N^2) = %d\n\n", MaxN, MaxN*MaxN);
	printf("В нашем случае количество операций:\n");
	Sort1(MaxN, &a, &c_if, &c_swap);
	printf("Классический алгоритм: %d\n", c_if + c_swap);
	Sort2(MaxN, &b, &c_if, &c_swap);
	printf("Оптимизированный алгоритм: %d\n", c_if + c_swap);
	Sort3(MaxN, &c, &c_if, &c_swap);
	printf("Шейкерная сортировка: %d\n", c_if + c_swap);

	pause();
}

// 5. ** Реализовать сортировку вставками, используя бинарный поиск.
