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
	printf(" 1 - Задача 01 (сортировка подсчетом)\n");
	printf(" 2 - Задача 02 (быстрая сортировка)\n");
	printf(" 3 - Задача 03 (сортировка слиянием)\n");
	printf(" 3 - Задача 04 (сортировка со списком)\n\n");
	printf(" 0 - выход\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\nНажмите <Enter> для продолжения...");
	getch();
}

// 1. Реализовать сортировку подсчетом
//
void task01()
{
	printf("Задача 01 (сортировка подсчетом)\n\n");

	pause();
}

// 2. Реализовать быструю сортировку.
//
void task02()
{
	printf("Задача 02 (быстрая сортировка)\n\n");

	pause();
}

// 3. *Реализовать сортировку слиянием.
//
void task03()
{
	printf("Задача 03 (сортировка слиянием)\n\n");

	pause();
}

// 4. **Реализовать алгоритм сортировки со списком
//
void task04()
{
	printf("Задача 04 (сортировка со списком)\n\n");

	pause();
}
