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
#pragma warning(disable:6011)
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
// === Универсальный стек ===
// описание типов
struct TNode
{
	// вместо данных - нетипизированная ссылка
	void* value;
	struct TNode* next;
};

typedef struct TNode TNode;

struct TStack
{
	TNode* head;
	int size;
	int maxSize;
};

typedef struct TStack TStack;

// пуш
int push(TStack* Stack, void* value)
{
	if (Stack->size >= Stack->maxSize)
	{
		return -1;
	}
	TNode* tmp = (TNode*)malloc(sizeof(TNode));
	tmp->value = value;
	tmp->next = Stack->head;
	Stack->head = tmp;
	Stack->size++;
	return 0;
}

// поп
void* pop(TStack* Stack)
{
	if (Stack->size == 0)
	{
		return NULL;
	}
	TNode* tmp = NULL;
	void* value = Stack->head->value;
	tmp = Stack->head;
	Stack->head = Stack->head->next;
	free(tmp);
	Stack->size--;
	return value;
}

// Очистка стека (но не удаление!)
void Erase(TStack* Stack)
{
	TNode* current = Stack->head;
	TNode* next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	Stack->head = NULL;
	Stack->size = 0;
}

// Инициализация нового стека
void Init(TStack* Stack, int maxSize)
{
	Stack->maxSize = maxSize;
	Stack->size = 0;
	Stack->head = NULL;
}
// === конец универсальной части ===

// вывод стека на экран (для стека с данными типа int)
void PrintStackInt(TStack* Stack)
{
	TNode* current = Stack->head;
	while (current != NULL)
	{
		printf("%d", *(int*)current->value);
		current = current->next;
	}
}

// получение ссылки на значение типа int
int* GetIntP(int num)
{
	int* tmp = (int*)malloc(sizeof(int));
	*tmp = num;
	return tmp;
}

void task01()
{	
	printf("Задача 01 (перевод из десятичной в двоичную систему)\n\n");
	
	int num;
	
	// объявление стека
	TStack* Stack = (TStack*)malloc(sizeof(TStack));
	Init(Stack, 100);

	printf("Число в десятичной системе: ");
	scanf("%d", &num);
	while (num != 0)
	{
		// если стек ещё не полный
		if (Stack->size < Stack->maxSize)
		{
			// кладем в стек остаток от деления на 2
			push(Stack, GetIntP(num % 2));
			num /= 2;
		}
		else
		{
			printf("Переполнение стека/n");
		}
	}
	printf("Число в двоичной системе: ");
	// получаем значение в 2-ичной системе
	PrintStackInt(Stack);
	printf("\n");
	// очищение и удаление стека
	Erase(Stack);
	free(Stack);

	pause();
}

// 2. Написать программу, которая определяет, является ли введенная скобочная
// последовательность правильной.Примеры правильных скобочных выражений : (), ([])(), {}(),
// ([{}]), неправильных — )(, ())({ ), (, ]) }), ([(]) для скобок[, (, { .
// Например: (2 + (2 * 2)) или[2 / {5 * (4 + 7)}].
//
// получение ссылки на символ
char* GetCharP(char value)
{
	char* tmp = (char*)malloc(sizeof(char));
	tmp[0] = value;
	tmp[1] = '\0';
	return tmp;
}

void task02()
{
	printf("Задача 02 (скобочные последовательности)\n\n");

	// объявление и инициализация стека
	TStack* Stack = (TStack*)malloc(sizeof(TStack));
	Init(Stack, 100);

	// исходная строка
	char* expr = (char*)malloc(100*sizeof(char));

	printf("Скобочная последовательность: ");
	scanf("%s", expr);

	int index = 0;
	int result = 0;
	void* symbol;

	while (expr[index] != '\0')
	{
		switch (expr[index])
		{
		// если скобка открывающая, то заталкиваем её в стек
		case '(':
		case '[':
		case '{':
		case '<':
			push(Stack, GetCharP(expr[index]));
			break;
		// если скобка закрывающая, то получаем скобку из стека и проверяем соответствие
		case ')':
			result = -1;
			symbol = pop(Stack);
			if (symbol != NULL)
			{
				if (*(char*)symbol == '(')
				{
					result = 0;
				}
			}
			break;
		case ']':
			result = -1;
			symbol = pop(Stack);
			if (symbol != NULL)
			{
				if (*(char*)symbol == '[')
				{
					result = 0;
				}
			}
			break;
		case '}':
			result = -1;
			symbol = pop(Stack);
			if (symbol != NULL)
			{
				if (*(char*)symbol == '{')
				{
					result = 0;
				}
			}
			break;
		case '>':
			result = -1;
			symbol = pop(Stack);
			if (symbol != NULL)
			{
				if (*(char*)symbol == '<')
				{
					result = 0;
				}
			}
			break;
		}
		if (result == -1)
		{
			break;
		}
		else
		{
			index++;
		}
	}
	if ((result == 0) && (Stack->size == 0))
	{
		printf("Скобочная последовательность правильная\n");
	}
	else
	{
		printf("Скобочная последовательность не правильная\n");
	}
	
	Erase(Stack);
	free(Stack);

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
