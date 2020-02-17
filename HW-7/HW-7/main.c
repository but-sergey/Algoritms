// ================================================================
// Внимание!!! Для отображения русских букв (в Win7) в окне консоли
// в свойствах изменить шрифт на Lucida Console!
// ================================================================

// Курс "Алгоритмы и структуры данных"
// Практическая работа №7
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
//		case 4: task04();
//			break;
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
	//printf(" 4 - Задача 04 (библиотека функций для работы с графами)\n\n");
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

int** ReadMatrix(char* fileName, int* N)
{
	// объявление переменной файла
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("Файл не найден!\n");
		return NULL;
	}
	
	// чтение из файла размера матрицы
	fscanf(file, "%d", N);
	
	// резервирование памяти под матрицу
	int** Matrix = (int**)malloc(*N * sizeof(int*));
	for (int i = 0; i < *N; i++)
	{
		Matrix[i] = (int*)malloc(*N * sizeof(int));
	}

	// чтение матрицы из файла
	for (int i = 0; i < *N; i++)
	{
		for (int j = 0; j < *N; j++)
		{
			fscanf(file, "%d", &Matrix[i][j]);
		}
	}

	return Matrix;
}

void PrintMatrix(int** Matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%4d ", Matrix[i][j]);
		}
		printf("\n");
	}
}

void FreeMatrix(int** Matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		free(Matrix[i]);
	}
	free(Matrix);
	Matrix = NULL;
}

void task01()
{
	printf("Задача 01 (матрица смежности)\n\n");

	int N;
	int** Matrix = ReadMatrix("..\\matrix.txt", &N);

	PrintMatrix(Matrix, N);

	FreeMatrix(Matrix, N);

	pause();
}

// 2. Написать рекурсивную функцию обхода графа в глубину.
//
// Сделаем два стека - 1 для запоминания ещё не обработанных вершин
// и 2 для запоминания уже обработанных

// === реализация стека
struct TNode
{
	int value;
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

int push(TStack* Stack, int value)
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

/*int* pop(TStack* Stack)
{
	if (Stack->size == 0)
	{
		return NULL;
	}
	TNode* tmp = NULL;
	int* value = (int*)malloc(sizeof(int));
	*value = Stack->head->value;
	tmp = Stack->head;
	Stack->head = Stack->head->next;
	free(tmp);
	Stack->size--;
	return value;
}*/

// освобождение стека
void FreeStack(TStack Stack)
{
	TNode* current = Stack.head;
	TNode* tmp;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
// === конец реализации стека

// рекурсивный обход графа в глубину
void DeepTraverse(TStack* processed, int** Matrix, int node, int N)
{
	TNode* current = processed->head;
	BOOL flag = FALSE;
	while (current != NULL)
	{
		if (current->value == node)
		{
			flag = TRUE;
			break;
		}
		current = current->next;
	}

	// если вершина ещё не обработана...
	if (!flag)
	{
		printf("%d ", node);
		push(processed, node);
		for (int i = 0; i < N; i++)
		{
			if (Matrix[node][i] != 0)
			{
				DeepTraverse(processed, Matrix, i, N);
			}
		}
	}
}

void task02()
{
	printf("Задача 02 (обход графа в глубину)\n\n");

	// чтение графа
	int N;
	int** Matrix = ReadMatrix("..\\matrix.txt", &N);

	PrintMatrix(Matrix, N);
	printf("\n");

	// Список (стек) обработанных вершин
	TStack processed;
	processed.head = NULL;
	processed.size = 0;
	processed.maxSize = 100;

	// обход в глубину
	printf("Обход графа \"в глубину\": ");
	DeepTraverse(&processed, Matrix, 0, N);
	printf("\n");

	// освобождение памяти
	FreeMatrix(Matrix, N);
	FreeStack(processed);

	pause();
}

// 3. Написать функцию обхода графа в ширину
//

// === реализация очереди
struct TQueue
{
	TNode* head;
	int size;
	int maxSize;
};
typedef struct TQueue TQueue;

int pushQ(TQueue* Queue, int value)
{
	if (Queue->size >= Queue->maxSize)
	{
		return -1;
	}
	TNode* tmp = (TNode*)malloc(sizeof(TNode));
	tmp->value = value;
	tmp->next = Queue->head;
	Queue->head = tmp;
	Queue->size++;
	return 0;
}

int* popQ(TQueue* Queue)
{
	// если очередь пуста, возвращаем NULL
	if (Queue->size == 0)
	{
		return NULL;
	}
	// переходим в конец очереди
	TNode* tmp = Queue->head;
	TNode* tmpPrev = NULL;
	while (tmp->next != NULL)
	{
		tmpPrev = tmp;
		tmp = tmp->next;
	}
	// вытаскиваем значение
	int* value = (int*)malloc(sizeof(int));
	*value = tmp->value;

	// удаляем узел
	if (tmpPrev != NULL)
	{
		tmpPrev->next = NULL;
	}
	else
	{
		Queue->head = NULL;
	}
	free(tmp);
	Queue->size--;
	
	return value;
}

// освобождение очереди
void FreeQueue(TQueue Queue)
{
	TNode* current = Queue.head;
	TNode* tmp;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
// === конец реализации очереди

// обход графа в ширину
void WidthTraverse(int** Matrix, int node, int N)
{
	// очередь вершин, ожидающих обработки
	TQueue* toProcess = (TQueue*)malloc(sizeof(TQueue));
	toProcess->head = NULL;
	toProcess->size = 0;
	toProcess->maxSize = 100;

	// стек(список) обработанных вершин
	TStack* processed = (TStack*)malloc(sizeof(TStack));
	processed->head = NULL;
	processed->size = 0;
	processed->maxSize = 100;

	TNode* tmpNode;

	int current;
	BOOL flag;

	pushQ(toProcess, node);

	while (toProcess->size != 0)
	{
		// извлекаем вершину из очереди, обрабатываем (вывод в консоль)
		current = *popQ(toProcess);
		printf("%d ", current);
		push(processed, current);
		
		// поиск необработанных смежных вершин
		for (int i = 0; i < N; i++)
		{
			if (Matrix[current][i] != 0)
			{
				// проверка обработана смежная вершина или нет
				tmpNode = processed->head;
				flag = FALSE;
				while (tmpNode != NULL)
				{
					if (tmpNode->value == i)
					{
						flag = TRUE;
						break;
					}
					tmpNode = tmpNode->next;
				}
				// если вершина не обработана, ставим её в очередь на обработку
				if (!flag)
				{
					pushQ(toProcess, i);
				}
			}
		}
	}
}

void task03()
{
	printf("Задача 03 (обход графа в ширину)\n\n");

	// чтение графа
	int N;
	int** Matrix = ReadMatrix("..\\matrix.txt", &N);

	PrintMatrix(Matrix, N);
	
	// обход в ширину
	printf("Обход графа \"в ширину\": ");
	WidthTraverse(Matrix, 0, N);
	printf("\n");

	// освобождение памяти
	FreeMatrix(Matrix, N);

	pause();
}

// 4. *Создать библиотеку функций для работы с графами.
//
void task04()
{
	printf("Задача 04 (библиотека функций для работы с графами)\n\n");

	pause();
}
