// ================================================================
// Внимание!!! Для отображения русских букв (в Win7) в окне консоли
// в свойствах изменить шрифт на Lucida Console!
// ================================================================

// Курс "Алгоритмы и структуры данных"
// Практическая работа №4
// Бут Сергей

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#pragma warning(disable:6385)
#pragma warning(disable:6386)

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
	printf(" 1 - Задача 01 (количество маршрутов)\n");
	printf(" 2 - Задача 02 (длина максимальной последовательности)\n");
	printf(" 3 - Задача 03 (шахматный конь)\n\n");
	printf(" 0 - выход\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\nНажмите <Enter> для продолжения...");
	getch();
}

// 1. *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и
// нахождение количество маршрутов.
// Например, карта:
// 3 3
// 1 1 1
// 0 1 0
// 0 1 0
//
void task01()
{
	printf("Задача 01 (количество маршрутов)\n\n");
	
	char fileName[] = "..\\map.txt";
	FILE* mapFile = fopen(fileName, "r");

	if (mapFile != NULL)
	{
		// чтение размера карты
		int N, M;
		fscanf(mapFile, "%d %d", &N, &M);
		
		// создание динамического двумерного массива - карты
		int** map = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++)
		{
			map[i] = (int*)malloc(M * sizeof(int));
		}

		// чтение карты из файла
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				fscanf(mapFile, "%d", &map[i][j]);
			}
		}
		
		// вывод массива (контроль)
		printf("Карта:\n");
		for (int i = 0; i < N; i++)
		{	
			for (int j = 0; j < M; j++)
			{
				printf("%5d ", map[i][j]); 
			}
			printf("\n");
		}
		printf("\n");
		// закрытие файла
		fclose(mapFile);
		
		// алгоритм
		// создание динамического двумерного массива решений
		int** ways = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++)
		{
			ways[i] = (int*)malloc(M * sizeof(int));
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
				{
					ways[i][j] = 0;
				}
				else if ((i == 0) || (j == 0))
				{
					ways[i][j] = 1;
				}
				else 
				{
					ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
				}
			}
		}
		// вывод массива
		printf("Количество маршрутов до соответствующих точек:\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%5d ", ways[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	else
	{
		printf("Не удалось открыть файл %s\n", fileName);
	}

	pause();
}

// 2. Решить задачу о нахождении длины максимальной последовательности с помощью матрицы
//
void task02()
{
	printf("Задача 02 (длина максимальной последовательности)\n\n");

	pause();
}

// 3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по
// одному разу.Здесь алгоритм решения такой же как и в задаче о 8 ферзях.Разница только в проверке
// положения коня.
//
void task03()
{
	printf("Задача 03 (шахматный конь)\n\n");

	pause();
}
