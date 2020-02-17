// ================================================================
// Внимание!!! Для отображения русских букв (в Win7) в окне консоли
// в свойствах изменить шрифт на Lucida Console!
// ================================================================

// Курс "Алгоритмы и структуры данных"
// Практическая работа №6
// Бут Сергей

#include<stdio.h>
#include<stdlib.h>
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
	printf(" 1 - Задача 01 (хэш-функция)\n");
	printf(" 2 - Задача 02 (двоичное дерево поиска)\n");
	//printf(" 3 - Задача 03 (база данных студентов)\n\n");
	printf(" 0 - выход\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\nНажмите <Enter> для продолжения...");
	getch();
}

// 1. Реализовать простейшую хэш-функцию. На вход функции подается строка, на выходе сумма кодов
// символов.
//
int SimpleHash(char *in)
{
	int out = 0;
	int i = 0;
	while (in[i] != '\0')
	{
		out += (int) in[i];
		i++;
	}
	return out;
}

void task01()
{
	printf("Задача 01 (хэш-функция)\n\n");

	char* str_in = (char*)malloc(100 * sizeof(char));

	printf("Строка для вычисления хеш-суммы: ");
	scanf("%s", str_in);

	printf("\nХеш-сумма введенной строки: %d\n", SimpleHash(str_in));

	pause();
}

// 2. Переписать программу, реализующее двоичное дерево поиска.
//   а) Добавить в него обход дерева различными способами;
//   б) Реализовать поиск в двоичном дереве поиска;
//   в)* Добавить в программу обработку командной строки с помощью которой можно указывать
//   из какого файла считывать данные, каким образом обходить дерево.
//
typedef int T;
typedef struct Node
{
	T data;
	struct Node* left;
	struct Node* right;
	struct Node* parent;
} Node;

// Распечатка двоичного дерева в виде скобочной записи
void printTree(Node* root)
{
	if (root)
	{
		printf("%d", root->data);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
				printTree(root->left);
			else
				printf("NULL");
			printf(",");

			if (root->right)
				printTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

// Создание нового узла
Node* getFreeNode(T value, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->data = value;
	tmp->parent = parent;
	return tmp;
}

// Вставка узла
void insert(Node** head, int value)
{
	Node* tmp = NULL;
	if (*head == NULL)
	{
		*head = getFreeNode(value, NULL);
		return;
	}

	tmp = *head;
	while (tmp)
	{
		if (value > tmp->data)
		{
			if (tmp->right)
			{
				tmp = tmp->right;
				continue;
			}
			else
			{
				tmp->right = getFreeNode(value, tmp);
				return;
			}
		}
		else if (value < tmp->data)
		{
			if (tmp->left)
			{
				tmp = tmp->left;
				continue;
			}
			else
			{
				tmp->left = getFreeNode(value, tmp);
				return;
			}
		}
		else
		{
			printf("Дерево построено неправильно");
			return;
		}
	}
}

void preOrderTravers(Node* root)
{
	if (root)
	{
		printf("%d ", root->data);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}

void inOrderTravers(Node* root)
{
	if (root)
	{
		inOrderTravers(root->left);
		printf("%d ", root->data);
		inOrderTravers(root->right);
	}
}

void postOrderTravers(Node* root)
{
	if (root)
	{
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		printf("%d ", root->data);
	}
}

void task02()
{
	printf("Задача 02 (двоичное дерево поиска)\n\n");

	Node* Tree = NULL;
	char* fileName = "..\\data.txt";
	FILE* file = fopen(fileName, "r");
	if (file == NULL)
	{
		printf("Невозможно открыть файл!\n");
		pause();
		return;
	}
	int count;
	fscanf(file, "%d", &count);
	for (int i = 0; i < count; i++)
	{
		int value;
		fscanf(file, "%d", &value);
		insert(&Tree, value);
	}
	fclose(file);
	printTree(Tree);
	printf("\n");
	
	printf("\nPreOrderTravers:  ");
	preOrderTravers(Tree);
	
	printf("\nInOrderTravers:   ");
	inOrderTravers(Tree);
	
	printf("\nPostOrderTravers: ");
	postOrderTravers(Tree);
	
	printf("\n");

	pause();
}

// 3. *Разработать базу данных студентов из двух полей “Имя”, “Возраст”, “Табельный номер” в которой
// использовать все знания, полученные на уроках.
// Считайте данные в двоичное дерево поиска.Реализуйте поиск по какому - нибудь полю базы данных
// (возраст, вес)
//
void task03()
{
	printf("Задача 03 (база данных студентов)\n\n");

	pause();
}
