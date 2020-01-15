// ================================================================
// Внимание!!! Для отображения русских букв (в Win7) в окне консоли
// в свойствах изменить шрифт на Lucida Console!
// ================================================================

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
	printf(" 1 - Задача 01 (ИМТ)\n");
	printf(" 2 - Задача 02 (максимальное из 4 чисел)\n");
	printf(" 3 - Задача 03 (обмен значениями 2 переменных)\n");
	printf(" 4 - Задача 04 (квадратное уравнение)\n");
	printf(" 5 - Задача 05 (месяц и времена года)\n");
	printf(" 6 - Задача 06 (возраст)\n");
	printf(" 7 - Задача 07 (клетки на шахматной доске)\n");
	printf(" 8 - Задача 08 (квадраты и кубы чисел)\n");
	printf(" 9 - Задача 09 (деление вычитанием)\n");
	printf("10 - Задача 10 (нечетные цифры в числе)\n");
	printf("11 - Задача 11 (среднее арифметическое чисел)\n");
	printf("12 - Задача 12 (функция нахождения максимального из 3х чисел)\n");
	printf("13 - Задача 13 (случайное число)\n");
	printf("14 - Задача 14 (автоморфные числа)\n");
	printf("\n");
	printf("0 - выход\n");
}

void pause()
{
	printf("Нажмите <Enter> для продолжения...");
	getch();
}

// 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы
// тела по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.
//
void task01()
{
	printf("Задача 01 (ИМТ)\n\n");

	double m;
	double h;
	double I;

	printf("Масса, кг: ");
	scanf("%lf", &m);

	printf("Рост, м: ");
	scanf("%lf", &h);

	I = m / (h * h);
	printf("ИМТ = %.2lf\n", I);

	pause();
}

// 2. Найти максимальное из четырех чисел. Массивы не использовать.
//
void task02()
{
	printf("Задача 02 (максимальное из 4 чисел)\n");

	int x1, x2, x3, x4;
	int max, max1, max2;
	
	printf("Число №1: ");
	scanf("%d", &x1);

	printf("Число №2: ");
	scanf("%d", &x2);

	printf("Число №3: ");
	scanf("%d", &x3);

	printf("Число №4: ");
	scanf("%d", &x4);

	max1 = (x1 > x2) ? x1 : x2;
	max2 = (x3 > x4) ? x3 : x4;
	max = (max1 > max2) ? max1 : max2;

	printf("Максимальное число = %d\n", max);

	pause();
}

// 3. Написать программу обмена значениями двух целочисленных переменных :
// a. с использованием третьей переменной;
// b.* без использования третьей переменной.
//
void task03()
{
	printf("Задача 03 (обмен значениями 2 переменных)\n");

	int a = 1;
	int b = 2;
	int t;

	printf("a = %d, b = %d\n", a, b);
	t = a;
	a = b;
	b = t;
	printf("a = %d, b = %d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a = %d, b = %d\n", a, b);
	a = a * b;
	b = a / b;
	a = a / b;
	printf("a = %d, b = %d\n", a, b);
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	printf("a = %d, b = %d\n", a, b);

	pause();
}

// 4. Написать программу нахождения корней заданного квадратного уравнения.
//
void task04()
{
	printf("Задача 04 (квадратное уравнение)\n");
	double a, b, c;
	double D, x1, x2;

	printf("a*x^2 + b*x + c = 0\n");
	
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);

	if (a == 0)
	{
		if (b == 0)
		{
			printf("Это не уравнение, a или b не должно равняться 0.\n");
		}
		else
		{
			x1 = -c / b;
			printf("Линейное уравнение, x = %.2lf.\n", x1);
		}
	}
	else
	{
		D = b * b - 4 * a * c;
		printf("D = %.2lf\n", D);
		if (D == 0)
		{
			x1 = -b / (2 * a);
			printf("Два одинаковых корня, x1 = x2 = %.2lf.\n", x1);
		}
		else if (D > 0)
		{
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			printf("Два действительных корня: x1 = %.2lf и x2 = %.2lf.\n", x1, x2);
		}
		else
		{	// здесь можно было бы ещё расписать комплексные корни, но лень... )))
			printf("На множестве действительных чисел уравнение корней не имеет.\n");
		}
	}

	pause();
}

// 5. С клавиатуры вводится номер месяца.Требуется определить, к какому
// времени года он относится.
//
void task05()
{
	printf("Задача 05 (месяц и времена года)\n");

	int month;

	printf("Номер месяца: ");
	scanf("%d", &month);
	
	switch (month)
	{
	case 12:
	case 1:
	case 2: printf("Это зима.\n");
		break;
	case 3:
	case 4:
	case 5: printf("Это весна.\n");
		break;
	case 6:
	case 7:
	case 8: printf("Это лето.\n");
		break;
	case 9:
	case 10:
	case 11: printf("Это зима.\n");
		break;
	default:
		printf("Неверный номер месяца.\n");
	}
	
	pause();
}

// 6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с
// последующим словом «год», «года» или «лет».
//
void task06()
{
	printf("Задача 06 (возраст)\n");
	
	int age;

	printf("Ваш возраст: ");
	scanf("%d", &age);
	if ((age >= 1) && (age <= 150))
	{
		if ((age % 100 >= 11) && (age % 100 <= 14))
		{
			printf("Вам %d лет.\n", age);
		}
		else
		{
			switch (age % 10)
			{
			case 1: printf("Вам %d год.\n", age);
				break;
			case 2:
			case 3:
			case 4: printf("Вам %d года.\n", age);
				break;
			default: printf("Вам %d лет.\n", age);
			}
		}
	}
	else
	{
		printf("Неверный возраст. Возраст должен быть от 1 до 150 включительно.\n");
	}

	pause();
}

// 7. С клавиатуры вводятся числовые координаты двух полей шахматной
// доски(x1, y1, x2, y2).Требуется определить, относятся поля к одному
// цвету или нет.
//
void task07()
{
	printf("Задача 07 (клетки на шахматной доске)\n");

	int x1, y1, x2, y2;
	
	printf("Координаты клетки №1, x1-y1: ");
	scanf("%d-%d", &x1, &y1);
	printf("Координаты клетки №2, x2-y2: ");
	scanf("%d-%d", &x2, &y2);

	printf("\nДалее исходим из условия, что левая нижняя клетка (1-1) белого цвета.\n\n");

	if ((x1 + y2) % 2 == (x2 + y2) % 2)
	{
		printf("Клетки одного цвета: %s.\n", ((x1 + y1) % 2 == 0) ? "белого" : "черного");
	}
	else
	{
		printf("Клетки разного цвета. Клетка №1 %s, а клетка №2 %s.\n",
					((x1 + y1) % 2 == 0) ? "белая" : "черная",
					((x2 + y2) % 2 == 0) ? "белая" : "черная");
	}

	pause();
}

// 8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
//
void task08()
{
	printf("Задача 08 (квадраты и кубы чисел)\n");

	int a, b;

	printf("Число a: ");
	scanf("%d", &a);
	printf("Число b: ");
	scanf("%d", &b);
	if (a <= b)
	{
		printf("    x       x^2       x^3\n\n");
		do
		{
			printf("%5d%10d%10d\n", a, a * a, a * a * a);
			a++;
		} while (a <= b);
	}
	else
	{
		printf("Число a не должно быть больше, чем число b");
	}

	pause();
}

// 9. Даны целые положительные числа N и K. Используя только операции
// сложения и вычитания, найти частное от деления нацело N на K, а
// также остаток от этого деления.
//
void task09()
{
	printf("Задача 09 (деление вычитанием)\n");

	int N, K;
	int Q = 0;
	int R = 0;

	printf("Делимое N: ");
	scanf("%d", &N);
	printf("Делитель K: ");
	scanf("%d", &K);

	while (N >= K)
	{
		N -= K;
		Q++;
	}
	R = N;

	printf("\nЧастное Q = %d, остаток R = %d\n", Q, R);

	pause();
}

// 10. Дано целое число N(> 0). С помощью операций деления нацело и взятия
// остатка от деления определить, имеются ли в записи числа N нечетные цифры.
// Если имеются, то вывести True, если нет — вывести False.
//
void task10()
{
	printf("Задача 10 (нечетные цифры в числе)\n");

	int N;
	boolean FlagOdd = FALSE;

	printf("Число N: ");
	scanf("%d", &N);

	while (N != 0)
	{
		if (N % 2 == 1)
		{
			FlagOdd = TRUE;
			break;
		}
		else
		{
			N = N / 10;
		}
	}
	printf("%s\n", FlagOdd ? "True" : "False");

	pause();
}

// 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее
// арифметическое всех положительных четных чисел, оканчивающихся на 8.
//
void task11()
{
	printf("Задача 11 (среднее арифметическое положительных чисел, оканчивающихся на 8)\n");

	int num;
	int count = 0;
	int i = 0;
	int sum = 0;

	do
	{
		i++;
		printf("Введите число №%d (0 для выхода): ", i);
		scanf("%d", &num);

		if ((num > 0) && (num % 10 == 8))
		{
			sum += num;
			count++;
		}
	} while (num != 0);

	if (count != 0)
	{
		printf("Среднее арифметическое = %f.\n", (float)sum / count);
	}
	else
	{
		printf("Положительных чисел, оканчивающихся на 8 не встречалось.\n");
	}

	pause();
}

// 12. Написать функцию нахождения максимального из трех чисел.
//
int Max3(int x1, int x2, int x3)
{
	int max;
	
	max = x1;
	if (x2 > max) { max = x2; }
	if (x3 > max) { max = x3; }

	return max;
}

void task12()
{
	printf("Задача 12 (функция нахождения максимального из 3х чисел)\n");

	int x1, x2, x3;
	
	printf("Число №1: ");
	scanf("%d", &x1);
	printf("Число №2: ");
	scanf("%d", &x2);
	printf("Число №3: ");
	scanf("%d", &x3);

	printf("Максимальное число: %d\n", Max3(x1, x2, x3));

	pause();
}

// 13. * Написать функцию, генерирующую случайное число от 1 до 100.
// а) с использованием стандартной функции rand()
// б) без использования стандартной функции rand()
//

int MyRand1(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

int GlobalRnd = 4;

int MyRand2(int min, int max)
{
	int a = 3;
	//int b = 0; // Переменную b не используем, иначе будет некорректное выдерживание границы min
	GlobalRnd = (a * GlobalRnd) % (max - min + 1) + min;
	return GlobalRnd;
}

void task13()
{
	printf("Задача 13 (случайное число)\n");

	int i = 0;
	int NumCount = 5;
	int RndNum;

	srand(time(NULL));
	printf("С использованием функции rand(): ");
	for (int i = 0; i < NumCount; i++)
	{
		printf("%d%s", MyRand1(1, 100), (i == NumCount - 1) ? ".\n" : ", ");
	}

	printf("Без использования функции rand(): ");
	for (int i = 0; i < NumCount; i++)
	{
		printf("%d%s", MyRand2(1, 100), (i == NumCount - 1) ? ".\n" : ", ");
	}

	pause();
}

// 14. * Автоморфные числа.Натуральное число называется автоморфным,
// если оно равно последним цифрам своего квадрата.Например, 25^2 = 625.
// Напишите программу, которая вводит натуральное число N и выводит на
// экран все автоморфные числа, не превосходящие N.
//
void task14()
{
	printf("Задача 14 (автоморфные числа)\n");
	


	pause();
}
