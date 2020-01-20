// ================================================================
// Внимание!!! Для отображения русских букв (в Win7) в окне консоли
// в свойствах изменить шрифт на Lucida Console!
// ================================================================

// Курс "Алгоритмы и структуры данных"
// Практическая работа №6
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
	printf(" 1 - Задача 01 (матрица смежности)\n");
	printf(" 2 - Задача 02 (обход графа в глубину)\n");
	printf(" 3 - Задача 03 (обход графа в ширину)\n");
	printf(" 3 - Задача 04 (библиотека функций для работы с графами)\n\n");
	printf(" 0 - выход\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\nНажмите <Enter> для продолжения...");
	getch();
}

// 1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран
//
void task01()
{
	printf("Задача 01 (матрица смежности)\n\n");

	pause();
}

// 2. Написать рекурсивную функцию обхода графа в глубину.
//
void task02()
{
	printf("Задача 02 (обход графа в глубину)\n\n");

	pause();
}

// 3. Написать функцию обхода графа в ширину
//
void task03()
{
	printf("Задача 03 (обход графа в ширину)\n\n");

	pause();
}

// 4. *Создать библиотеку функций для работы с графами.
//
void task04()
{
	printf("Задача 04 (библиотека функций для работы с графами)\n\n");

	pause();
}
