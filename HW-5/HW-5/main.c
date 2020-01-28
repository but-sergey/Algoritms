// ================================================================
// Внимание!!! Для отображения русских букв (в Win7) в окне консоли
// в свойствах изменить шрифт на Lucida Console!
// ================================================================

// Курс "Алгоритмы и структуры данных"
// Практическая работа №5
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
void task05();
void task06();

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
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	system("cls");
	printf(" 1 - Задача 01 (перевод из десятичной в двоичную систему)\n");
	printf(" 2 - Задача 02 (скобочные последовательности)\n");
	printf(" 3 - Задача 03 (копирование односвязного списка)\n");
	printf(" 3 - Задача 04 (перевод из инфиксной записи в постфиксную)\n");
	printf(" 3 - Задача 05 (реализация очереди)\n");
	printf(" 3 - Задача 06 (двусторонняя очередь)\n\n");
	printf(" 0 - выход\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\nНажмите <Enter> для продолжения...");
	getch();
}

// 1. Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
//

#define T short

struct TNode
{
	T value;
	struct TNode* next;
};

typedef struct TNode Node;

struct Stack
{
	Node* head;
	int size;
	int maxSize;
};

struct Stack Stack;

int push(T value)
{
	if (Stack.size >= Stack.maxSize)
	{
		return -1;
	}
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = Stack.head;
	Stack.head = tmp;
	Stack.size++;
	return 0;
}

T pop()
{
	if (Stack.size == 0)
	{
		return NULL;
	}
	Node* next = NULL;
	T value;
	value = Stack.head->value;
	next = Stack.head;
	Stack.head = Stack.head->next;
	free(next);
	Stack.size--;
	return value;
}

void PrintStack()
{
	Node* current = Stack.head;
	while (current != NULL)
	{
		printf("%d", current->value);
		current = current->next;
	}
}

void EraseStack()
{
	Node* current = Stack.head;
	Node* next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	Stack.head = NULL;
	Stack.size = 0;
}

void task01()
{	
	printf("Задача 01 (перевод из десятичной в двоичную систему)\n\n");
	
	int num;
	Stack.maxSize = 100;

	printf("Число в десятичной системе: ");
	scanf("%d", &num);
	while (num != 0)
	{
		if (push(num % 2) == 0)
		{
			num /= 2;
		}
		else
		{
			printf("Переполнение стека/n");
		}
	}
	printf("Число в двоичной системе: ");
	PrintStack();
	EraseStack();
	printf("\n");

	pause();
}

// 2. Написать программу, которая определяет, является ли введенная скобочная
// последовательность правильной.Примеры правильных скобочных выражений : (), ([])(), {}(),
// ([{}]), неправильных — )(, ())({ ), (, ]) }), ([(]) для скобок[, (, { .
// Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}].
//
void task02()
{
	printf("Задача 02 (скобочные последовательности)\n\n");

	pause();
}

// 3. *Создать функцию, копирующую односвязный список (то есть создающую в памяти копию
// односвязного списка без удаления первого списка).
//
void task03()
{
	printf("Задача 03 (копирование односвязного списка)\n\n");

	pause();
}

// 4. *Реализовать алгоритм перевода из инфиксной записи арифметического выражения в
// постфиксную
//
void task04()
{
	printf("Задача 04 (перевод из инфиксной записи в постфиксную)\n\n");

	pause();
}

// 5. Реализовать очередь:
//   1. С использованием массива.
//   2. *С использованием односвязного списка.
//
void task05()
{
	printf("Задача 05 (реализация очереди)\n\n");

	pause();
}

// 6. ***Реализовать двустороннюю очередь.
//
void task06()
{
	printf("Задача 06 (двусторонняя очередь)\n\n");

	pause();
}
