#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:6031)

// Курс "Алгоритмы и структуры данных"
// Практическая работа №1
// Бут Сергей

void menu();
void task01();
void task02();
void task03();
void task04();
void task05();
void task06();
void task07();
void task08();
void task09();
void task10();
void task11();
void task12();
void task13();
void task14();

int main(int argc, const char* argv[])
{
	int sel = 0;
	do
	{
		menu();
		scanf("%i", &sel);
		system("cls");
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
		case 7: task07();
			break;
		case 8: task08();
			break;
		case 9: task09();
			break;
		case 10: task10();
			break;
		case 11: task11();
			break;
		case 12: task12();
			break;
		case 13: task13();
			break;
		case 14: task14();
			break;
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	system("cls");
	printf("1 - task01\n");
	printf("2 - task02\n");
	printf("3 - task03\n");
	printf("4 - task04\n");
	printf("5 - task05\n");
	printf("6 - task06\n");
	printf("7 - task07\n");
	printf("8 - task08\n");
	printf("9 - task09\n");
	printf("10 - task10\n");
	printf("11 - task11\n");
	printf("12 - task12\n");
	printf("13 - task13\n");
	printf("14 - task14\n");
	printf("\n");
	printf("0 - exit\n");
}

void pause()
{
	printf("Press <Enter> to continue...");
	getch();
}

// 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы
// тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
//
void task01()
{
	printf("Task 01\n");

	pause();
}

// 2. Найти максимальное из четырех чисел. Массивы не использовать.
//
void task02()
{
	printf("Task 02\n");

	pause();
}

// 3. Написать программу обмена значениями двух целочисленных переменных :
// a. с использованием третьей переменной;
// b.* без использования третьей переменной.
//
void task03()
{
	printf("Task 03\n");

	pause();
}

// 4. Написать программу нахождения корней заданного квадратного уравнения.
//
void task04()
{
	printf("Task 04\n");

	pause();
}

// 5. С клавиатуры вводится номер месяца.Требуется определить, к какому
// времени года он относится.
//
void task05()
{
	printf("Task 05\n");

	pause();
}

// 6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с
// последующим словом «год», «года» или «лет».
//
void task06()
{
	printf("Task 06\n");

	pause();
}

// 7. С клавиатуры вводятся числовые координаты двух полей шахматной
// доски(x1, y1, x2, y2).Требуется определить, относятся поля к одному
// цвету или нет.
//
void task07()
{
	printf("Task 07\n");

	pause();
}

// 8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
//
void task08()
{
	printf("Task 08\n");

	pause();
}

// 9. Даны целые положительные числа N и K. Используя только операции
// сложения и вычитания, найти частное от деления нацело N на K, а
// также остаток от этого деления.
//
void task09()
{
	printf("Task 09\n");

	pause();
}

// 10. Дано целое число N(> 0). С помощью операций деления нацело и взятия
// остатка от деления определить, имеются ли в записи числа N нечетные цифры.
// Если имеются, то вывести True, если нет — вывести False.
//
void task10()
{
	printf("Task 10\n");

	pause();
}

// 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее
// арифметическое всех положительных четных чисел, оканчивающихся на 8.
//
void task11()
{
	printf("Task 11\n");

	pause();
}

// 12. Написать функцию нахождения максимального из трех чисел.
//
void task12()
{
	printf("Task 12\n");

	pause();
}

// 13. * Написать функцию, генерирующую случайное число от 1 до 100.
// а) с использованием стандартной функции rand()
// б) без использования стандартной функции rand()
//
void task13()
{
	printf("Task 13\n");

	pause();
}

// 14. * Автоморфные числа.Натуральное число называется автоморфным,
// если оно равно последним цифрам своего квадрата.Например, 25^2 = 625.
// Напишите программу, которая вводит натуральное число N и выводит на
// экран все автоморфные числа, не превосходящие N.
//
void task14()
{
	printf("Task 14\n");

	pause();
}
