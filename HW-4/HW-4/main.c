// ================================================================
// ��������!!! ��� ����������� ������� ���� (� Win7) � ���� �������
// � ��������� �������� ����� �� Lucida Console!
// ================================================================

// ���� "��������� � ��������� ������"
// ������������ ������ �4
// ��� ������

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#pragma warning(disable:6385)
#pragma warning(disable:6386)
#pragma warning(disable:6387)

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
	printf(" 1 - ������ 01 (���������� ���������)\n");
	printf(" 2 - ������ 02 (����� ������������ ������������������)\n");
	printf(" 3 - ������ 03 (��������� ����)\n\n");
	printf(" 0 - �����\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\n������� <Enter> ��� �����������...");
	getch();
}

// 1. *���������� ��������� � �������������. ����������� ������ ������� � ������������ �
// ���������� ���������� ���������.
// ��������, �����:
// 3 3
// 1 1 1
// 0 1 0
// 0 1 0
//
void task01()
{
	printf("������ 01 (���������� ���������)\n\n");
	
	char fileName[] = "..\\map.txt";
	FILE* mapFile = fopen(fileName, "r");

	if (mapFile != NULL)
	{
		// ������ ������� �����
		int N, M;
		fscanf(mapFile, "%d %d", &N, &M);
		
		// �������� ������������� ���������� ������� - �����
		int** map = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++)
		{
			map[i] = (int*)malloc(M * sizeof(int));
		}

		// ������ ����� �� �����
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				fscanf(mapFile, "%d", &map[i][j]);
			}
		}
		
		// ����� ������� (��������)
		printf("�����:\n");
		for (int i = 0; i < N; i++)
		{	
			for (int j = 0; j < M; j++)
			{
				printf("%5d ", map[i][j]); 
			}
			printf("\n");
		}
		printf("\n");
		// �������� �����
		fclose(mapFile);
		
		// ��������� ������ ������������� ���������� ������� �������
		int** ways = (int**)malloc(N * sizeof(int*));
		for (int i = 0; i < N; i++)
		{
			ways[i] = (int*)malloc(M * sizeof(int));
		}
		// ���������� ������� �������
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

		// ����� �������
		printf("���������� ��������� �� ��������������� �����:\n");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				printf("%5d ", ways[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		// ������������ ������, ���������� ��� �������
		for (int i = 0; i < N; i++)
		{
			free(map[i]);
			free(ways[i]);
		}
		free(map);
		free(ways);
	}
	else
	{
		printf("�� ������� ������� ���� %s\n", fileName);
	}

	pause();
}

// 2. ������ ������ � ���������� ����� ������������ ������������������ � ������� �������
//
void task02()
{
	printf("������ 02 (����� ������������ ������������������)\n\n");

	char *A;
	char *B;
	int N;
	int M;
	int LCS_len;
	char* LCS;
	A = (char*)malloc(100);
	B = (char*)malloc(100);
	LCS = (char*)malloc(100);

	printf("������ ������������������ (����. 100 ��������): ");
	scanf("%s", A);
	// A = "GEEKBRAINS"; // �� ������ �������
	N = strlen(A);
	printf("������ ������������������ (����. 100 ��������): ");
	scanf("%s", B);
	// B = "GEEKMINDS"; // �� ������ �������
	M = strlen(B);

	// ��������� ������ ��� �������
	int** count = (int**)malloc((N + 1) * sizeof(int*));
	for (int i = 0; i <= N; i++)
	{
		count[i] = (int*)malloc((M + 1) * sizeof(int));
	}

	// ���������� ������� � ������������ LCS
	LCS_len = 0;
	LCS[0] = '\0';
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			if ((i == 0) || (j == 0))
			{
				count[i][j] = 0;
			}
			else if (A[i-1] == B[j-1])
			{
				// ���������� ������ �������
				count[i][j] = 1 + count[i - 1][j - 1];
				// ������������ ������ ���
				LCS[count[i][j] - 1] = A[i - 1];
				LCS[count[i][j]] = '\0';
				// ���������� ����� ���
				LCS_len = count[i][j];
			}
			else
			{
				count[i][j] = max(count[i - 1][j], count[i][j - 1]);
			}
		}
	}

	// ����� ������� (��� ��������)
	/*printf("������� �������:\n");
	for (int i = -1; i <= N; i++)
	{
		for (int j = -1; j <= M; j++)
		{
			if (((i == -1) && (j < 1)) || ((i == 0) && (j == -1)))
			{
				printf("    "); 
			}
			else if ((i == -1) && (j > 0))
			{
				printf("   %c", B[j - 1]); 
			}
			else if ((j == -1) && (i > 0))
			{
				printf("   %c", A[i - 1]); 
			}
			else
			{
				printf("%4d", count[i][j]); 
			}
		}
		printf("\n");
	}
	*/
	printf("\n");
	printf("����� ���������� ����� ��������������������� ����� %d\n", LCS_len);
	printf("���������� ����� ���������������������: %s\n", LCS);

	// ������������ ������
	for (int i = 0; i <= N; i++)
	{
		free(count[i]);
	}
	free(count);
	
	pause();
}

// 3. ***��������� ������ ���� ��������� ����� �������� NxM, ������ ����� ��� ���� ����� ��
// ������ ����.����� �������� ������� ����� �� ��� � � ������ � 8 ������.������� ������ � ��������
// ��������� ����.
//
void task03()
{
	printf("������ 03 (��������� ����)\n\n");

	pause();
}
