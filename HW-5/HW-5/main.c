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
	printf(" 4 - Задача 04 (перевод из инфиксной записи в постфиксную)\n");
	printf(" 5 - Задача 05 (реализация очереди)\n");
	printf(" 6 - Задача 06 (двусторонняя очередь)\n\n");
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
// Копирование стека с данными типа int
TStack* CopyStackInt(TStack* Stack)
{
	// текущий узел
	TNode* node;
	TNode* newNode;

	// создание и инициализация нового стека
	TStack* NewStack = (TStack*)malloc(sizeof(TStack));
	Init(NewStack, Stack->maxSize);

	// копирование стека
	if (Stack->head != NULL)
	{
		NewStack->head = (TNode*)malloc(sizeof(TNode));
		newNode = NewStack->head;
		node = Stack->head;

		while (node != NULL)
		{
			// копирование данных
			newNode->value = GetIntP(*(int*)node->value);

			// создание очередного узла
			if (node->next != NULL)
			{
				newNode->next = (TNode*)malloc(sizeof(TNode));
				newNode = newNode->next;
			}
			else
			{
				newNode->next = NULL;
			}
			node = node->next;
		}
	}

	return NewStack;
}

// вывод стека на экран (для стека с данными типа int)
void PrintStackInt2(TStack* Stack)
{
	TNode* current = Stack->head;
	while (current != NULL)
	{
		printf("%d", *(int*)current->value);
		current = current->next;
		
		if (current == NULL)
		{
			printf(".\n");
		}
		else
		{
			printf(", ");
		}
	}
}

void task03()
{
	printf("Задача 03 (копирование односвязного списка)\n\n");

	// Создание и инициализация стека
	TStack* Stack = (TStack*)malloc(sizeof(TStack));
	Init(Stack, 10);

	// Заполнение стека данными
	srand(time(NULL));
	for (int i = 0; i <= 10; i++)
	{
		push(Stack, GetIntP(rand() % 100));
	}

	// Создание копии стека
	TStack* NewStack = CopyStackInt(Stack);
	
	// Вывод двух стеков
	printf("Первый стек: ");
	PrintStackInt2(Stack);
	printf("Второй стек: ");
	PrintStackInt2(NewStack);

	pause();
}

// 4. *Реализовать алгоритм перевода из инфиксной записи арифметического выражения в
// постфиксную
//
void task04()
{
	printf("Задача 04 (перевод из инфиксной записи в постфиксную)\n\n");

	// флаг ошибки
	int error = 0;
	
	// выделение памяти под исходную и преобразованную строку
	char* expr1 = (char*)malloc(100 * sizeof(char));
	char* expr2 = (char*)malloc(100 * sizeof(char));

	// временный стек действий
	TStack* Temp = (TStack*)malloc(sizeof(TStack));
	Init(Temp, 100);

	printf("Исходное выражение: ");
	scanf("%s", expr1);
	
	// вспомогательные переменные
	int ind = 0;
	int ind2 = 0;
	char* ch;

	while (!((expr1[ind] == '\0') && (Temp->size == 0)))
	{
		if (((expr1[ind] >= 'A') && (expr1[ind] <= 'Z')) || ((expr1[ind] >= 'a') && (expr1[ind] <= 'z')))
		{	// буква - имя переменной
			expr2[ind2] = expr1[ind];
			ind2++;
			ind++;
		}
		else if ((expr1[ind] == '+') || (expr1[ind] == '-'))
		{ // арифметические действия с низким приоритетом
			if (Temp->size == 0)
			{
				push(Temp, GetCharP(expr1[ind]));
				ind++;
			}
			else if (*(char*)Temp->head->value == '(')
			{
				push(Temp, GetCharP(expr1[ind]));
				ind++;
			}
			else
			{
				ch = (char*)pop(Temp);
				expr2[ind2] = ch[0];
				ind2++;
			}
		}
		else if ((expr1[ind] == '*') || (expr1[ind] == '/'))
		{ // арифметические действия с высоким приоритетом
			if (Temp->size == 0)
			{
				push(Temp, GetCharP(expr1[ind]));
				ind++;
			}
			else
			{
				ch = (char*)Temp->head->value;
				if ((ch[0] == '+') || (ch[0] == '-') || (ch[0] == '('))
				{
					push(Temp, GetCharP(expr1[ind]));
					ind++;
				}
				else
				{
					ch = (char*)pop(Temp);
					expr2[ind2] = ch[0];
					ind2++;
				}
			}
		}
		else if (expr1[ind] == '(')
		{ // открывающая скобка
			push(Temp, GetCharP(expr1[ind]));
			ind++;
		}
		else if (expr1[ind] == ')')
		{	// закрывающая скобка
			if (Temp->size == 0)
			{
				error = -1;
				break;
			}
			else
			{
				ch = (char*)pop(Temp);
				if (ch[0] != '(')
				{
					expr2[ind2] = ch[0];
					ind2++;
				}
				else
				{
					ind++;
				}
			}
		}
		else if (expr1[ind] == '\0')
		{ // входная строка закончилась
			ch = (char*)pop(Temp);
			if (ch[0] == '(')
			{
				error = -1;
				break;
			}
			else
			{
				expr2[ind2] = ch[0];
				ind2++;
			}
		}
	}

	expr2[ind2] = '\0';

	if (error == 0)
	{
		printf("Выражение в постфиксной записи: %s\n", expr2);
	}
	else
	{
		printf("\nВыражение не сбалансировано!\n");
	}

	Erase(Temp);
	free(Temp);
	
	pause();
}

// 5. Реализовать очередь:
//   1. С использованием массива.
//   2. *С использованием односвязного списка.
//
// === с использованием массива ===

#define maxQ 10

struct TQueue1
{
	int tail;
	int data[maxQ];
};

typedef struct TQueue1 TQueue1;

int pushQ1(TQueue1* queue, int value)
{
	if ((*queue).tail < maxQ - 1)
	{
		for (int i = (*queue).tail; i >= 0; i--)
		{
			(*queue).data[i + 1] = (*queue).data[i];
		}
		(*queue).tail++;
		(*queue).data[0] = value;
		return 0;
	}
	else
	{
		return -1;
	}
}

int popQ1(TQueue1* queue, int* value)
{
	if ((*queue).tail >= 0)
	{
		(*queue).tail--;
		*value = (*queue).data[(*queue).tail + 1];
	}
	else
	{
		return -1;
	}
}

// === с использованием односвязного списка

struct TNodeQ2
{
	int value;
	struct TNodeQ2* next;
};

typedef struct TNodeQ2 TNodeQ2;

struct TQueue2
{
	TNodeQ2* head;
	int size;
	int maxSize;
};

typedef struct TQueue2 TQueue2;

// пуш
int pushQ2(TQueue2* queue, int value)
{
	if (queue->size >= queue->maxSize)
	{
		return -1;
	}
	TNodeQ2* tmp = (TNodeQ2*)malloc(sizeof(TNodeQ2));
	tmp->value = value;
	tmp->next = queue->head;
	queue->head = tmp;
	queue->size++;
	return 0;
}

// поп
int popQ2(TQueue2* queue, int* value)
{
	if (queue->size == 0)
	{
		return -1;
	}
	else
	{
		queue->size--;

		TNodeQ2* current;
		current = queue->head;

		if (current->next == NULL)
		{
			*value = current->value;
			free(current);
			queue->head = NULL;
		}
		else
		{
			while (current->next->next != NULL)
			{
				current = current->next;
			}
			*value = current->next->value;
			free(current->next);
			current->next = NULL;
		}
		return 0;
	}
}

// Очистка очереди (но не удаление!)
void EraseQ2(TQueue2* queue)
{
	TNodeQ2* current = queue->head;
	TNodeQ2* next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	queue->head = NULL;
	queue->size = 0;
}

// Инициализация новоЙ очереди
void InitQ2(TQueue2* queue, int maxSize)
{
	queue->maxSize = maxSize;
	queue->size = 0;
	queue->head = NULL;
}

void task05()
{
	printf("Задача 05 (реализация очереди)\n\n");

	printf("С использованием массива\n");

	TQueue1 queue1;
	queue1.tail = -1;

	int value;
	srand(time(NULL));

	printf(" - в очередь: ");
	// заполнение очереди случайными данными
	for (int i = 0; i < 10; i++)
	{
		value = rand() % 100;
		pushQ1(&queue1, value);
		if (i != 9)
			printf("%d, ", value);
		else
			printf("%d.\n", value);
	}
	printf(" - из очереди: ");
	// извлечение данных из очереди
	while (queue1.tail != -1)
	{
		popQ1(&queue1, &value);
		if (queue1.tail != -1)
			printf("%d, ", value);
		else
			printf("%d.\n\n", value);
	}

	printf("С использоватнием односвязного списка\n");

	TQueue2 queue2;
	InitQ2(&queue2, 10);
	
	printf(" - в очередь: ");
	// заполнение очереди случайными данными
	for (int i = 0; i < 10; i++)
	{
		value = rand() % 100;
		pushQ2(&queue2, value);
		if (i != 9)
			printf("%d, ", value);
		else
			printf("%d.\n", value);
	}
	printf(" - из очереди: ");
	// извлечение данных из очереди
	while (queue2.size != 0)
	{
		popQ2(&queue2, &value);
		if (queue2.size != 0)
			printf("%d, ", value);
		else
			printf("%d.\n\n", value);
	}

	pause();
}

// 6. ***Реализовать двустороннюю очередь.
//
void task06()
{
	printf("Задача 06 (двусторонняя очередь)\n\n");

	pause();
}
