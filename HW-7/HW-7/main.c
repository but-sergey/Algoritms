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
// https://shpargalum.ru/shpora-gos-povtas/strukturyi-i-algoritmyi-obrabotki-dannyix/grafyi.-obxod-grafov-v-shirinu-i-glubinu.html
//
void task02()
{
	printf("Задача 02 (обход графа в глубину)\n\n");

	// чтение графа
	int N;
	int** Matrix = ReadMatrix("..\\matrix.txt", &N);

	PrintMatrix(Matrix, N);


	// освобождение памяти
	FreeMatrix(Matrix, N);

	pause();
}

// 3. Написать функцию обхода графа в ширину
//
void task03()
{
	printf("Задача 03 (обход графа в ширину)\n\n");

	// чтение графа
	int N;
	int** Matrix = ReadMatrix("..\\matrix.txt", &N);

	PrintMatrix(Matrix, N);



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
