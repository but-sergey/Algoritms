 // ================================================================
// Внимание!!! Для отображения русских букв (в Win7) в окне консоли
// в свойствах изменить шрифт на Lucida Console!
// ================================================================

// Курс "Алгоритмы и структуры данных"
// Практическая работа №2
// Бут Сергей

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<Windows.h>
#pragma warning(disable:6031)

void menu();
void task01();
void task02();
void task03();

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
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	system("cls");
	printf(" 1 - Задача 01 (перевод из десятичной в двоичную систему)\n");
	printf(" 2 - Задача 02 (возведение в степень)\n");
	printf(" 3 - Задача 03 (исполнитель \"Калькулятор\")\n");
	printf("\n");
	printf("0 - выход\n");
	printf("-> ");
}

void pause()
{
	printf("\nНажмите <Enter> для продолжения...");
	getch();
}

// 1. Реализовать функцию перевода чисел из десятичной системы в двоичную, используя
// рекурсию.
//
// === Вариант со строкой не взлетел. В рекурсию проваливается до конца нормально, а когда
// === начинает выходить и собирать ответ - Access Violation. Что не так?

/*char* DecToBin(int dec)
{
	char symbol;
	char* result;
	result = "";

	symbol = (int)'0' + (dec % 2);
	printf("%c", symbol);

	if (dec >= 2)
	{
		sprintf(result, "%s%c", DecToBin(dec / 2), symbol);
		//return strcpy(DecToBin(dec / 2), symbol);
	}
	else
	{
		result = "1";
		//strcpy(result, &symbol);
		//sprintf(result, "%c", symbol);
	}
	return result;
}*/

long int DecToBin(int dec)
{
	if (dec >= 2)
	{
		return DecToBin(dec / 2) * 10 + dec % 2;
	}
	else
	{
		return dec;
	}
}

void task01()
{
	printf("Задача 01 (перевод из десятичной в двоичную систему)\n\n");

	int dec;

	printf("Число в десятичной системе: ");
	scanf("%d", &dec);

	printf("Число в двоичной системе: %ld", DecToBin(dec));

	pause();
}

// 2. Реализовать функцию возведения числа a в степень b:
// a.Без рекурсии.
// b.Рекурсивно.
// c. *Рекурсивно, используя свойство чётности степени
//

// без рекурсии
long int MyPow1(int a, int b)
{
	long int result = 1;

	if (b > 0)
	{
		for (int i = 0; i < b; i++)
		{
			result *= a;
		}
	}
	else
	{
		result = -1;
	}

	return result;
}

// рекурсивно
long int MyPow2(int a, int b)
{
	if (b == 0)
	{
		return -1;
	}
	else if (b == 1)
	{
		return a;
	}
	else
	{
		return a * MyPow2(a, b - 1);
	}
}

// рекурсивно, используя свойство четности степени
long int MyPow3(int a, int b)
{
	if (b <= 0)
	{
		return -1;
	}
	else if (b == 1)
	{
		return a;
	}
	else if (b % 2 == 0)
	{
		long int result = MyPow3(a, b / 2);
		return result * result;
	}
	else
	{
		return a * MyPow3(a, b - 1);
	}
}

void task02()
{
	printf("Задача 02 (возведение в степень)\n\n");

	int a, b;
	
	printf("Основание a: ");
	scanf("%d", &a);
	printf("Показатель b: ");
	scanf("%d", &b);

	printf("Возведение в степень:\n");
	printf("%15ld - без рекурсии;\n", MyPow1(a, b));
	printf("%15ld - рекурсивно;\n", MyPow2(a, b));
	printf("%15ld - рекурсивно, используя четность степени.\n", MyPow3(a, b));

	pause();
}

// 3. *Исполнитель «Калькулятор» преобразует целое число, записанное на экране.У
// исполнителя две команды, каждой присвоен номер :
//   1. Прибавь 1.
//   2. Умножь на 2.
// Первая команда увеличивает число на экране на 1, вторая увеличивает его в 2 раза.Сколько
// существует программ, которые число 3 преобразуют в число 20 :
//   а.С использованием массива.
//   b. * С использованием рекурсии.
//
// === Здесь написал универсальный метод, границы (3 и 20) не жестко заданы в алгоритме, а
// === определены в переменных, их можно изменить

// с использованием массива
int Calc1(int min, int max)
{
	// счетчик программ
	int result = 0;
	// максимальное количество команд (когда все они +1)
	int count = max - min;
	// выделение памяти под динамический массив команд
	int* commands;
	commands = (int*)malloc(count * sizeof(int));
	// инициализация массива - все команды №1 (+1)
	for (int i = 0; i < count; i++)
	{
		commands[i] = 1;
		result++;
	}
	// признак окончания генерации (все команды = *2)
	boolean flagEnd;

	do
	{
		// принцип "от обратного", если флаг не сбросится, значит последняя итерация
		flagEnd = TRUE;

		// число, над которым выполняются действия
		int num = min;

		// генерация и проверка очередного набора команд
		commands[0] += 1;

		for (int i = 0; i < count - 1; i++)
		{
			// генерация очередной последовательности команд
			if (commands[i] > 2)
			{
				commands[i] = 1;
				commands[i + 1] += 1;
			}
			// выполнение действий над числом в соответствии с командами

			if (commands[i] == 1)
			{
				num += 1;
				// встречается команда +1, значит, не все варианты команд перебраны
				flagEnd = FALSE;
			}
			else if (commands[i] == 2)
			{
				num *= 2;
			}
			// проверка на достижение значения max
			if (num >= max)
			{
				if (num == max)
				{
					result++;
				}
				break;
			}
		}
	} while (flagEnd);

	return result;
}

// с использованием рекурсии
void CalcRecursive(int min, int max, int* count);

int Calc2(int min, int max)
{
	int count = 0;
	
	CalcRecursive(min, max, &count);
	
	return count;
}

void CalcRecursive(int min, int max, int* count)
{
	if (min == max)
	{
		*count += 1;
	}
	else if (min < max)
	{
		CalcRecursive(min + 1, max, count);
		CalcRecursive(min * 2, max, count);
	}
}

void task03()
{
	int min = 3;
	int max = 20;

	printf("Задача 03 (исполнитель \"Калькулятор\")\n\n");

	printf("Количество вариантов программ преобразования числа %d в %d:\n", min, max);
	printf(" - с использованием массива: %d\n", Calc1(min, max));
	printf(" - с использованием рекурсии: %d\n", Calc2(min, max));

	pause();
}
