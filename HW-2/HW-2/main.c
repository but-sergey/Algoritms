 // ================================================================
// ��������!!! ��� ����������� ������� ���� (� Win7) � ���� �������
// � ��������� �������� ����� �� Lucida Console!
// ================================================================

// ���� "��������� � ��������� ������"
// ������������ ������ �2
// ��� ������

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
	printf(" 1 - ������ 01 (������� �� ���������� � �������� �������)\n");
	printf(" 2 - ������ 02 (���������� � �������)\n");
	printf(" 3 - ������ 03 (����������� \"�����������\")\n");
	printf("\n");
	printf("0 - �����\n");
	printf("-> ");
}

void pause()
{
	printf("\n������� <Enter> ��� �����������...");
	getch();
}

// 1. ����������� ������� �������� ����� �� ���������� ������� � ��������, ���������
// ��������.
//
// === ������� �� ������� �� �������. � �������� ������������� �� ����� ���������, � �����
// === �������� �������� � �������� ����� - Access Violation. ��� �� ���?

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
	printf("������ 01 (������� �� ���������� � �������� �������)\n\n");

	int dec;

	printf("����� � ���������� �������: ");
	scanf("%d", &dec);

	printf("����� � �������� �������: %ld", DecToBin(dec));

	pause();
}

// 2. ����������� ������� ���������� ����� a � ������� b:
// a.��� ��������.
// b.����������.
// c. *����������, ��������� �������� �������� �������
//

// ��� ��������
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

// ����������
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

// ����������, ��������� �������� �������� �������
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
	printf("������ 02 (���������� � �������)\n\n");

	int a, b;
	
	printf("��������� a: ");
	scanf("%d", &a);
	printf("���������� b: ");
	scanf("%d", &b);

	printf("���������� � �������:\n");
	printf("%15ld - ��� ��������;\n", MyPow1(a, b));
	printf("%15ld - ����������;\n", MyPow2(a, b));
	printf("%15ld - ����������, ��������� �������� �������.\n", MyPow3(a, b));

	pause();
}

// 3. *����������� ������������ ����������� ����� �����, ���������� �� ������.�
// ����������� ��� �������, ������ �������� ����� :
//   1. ������� 1.
//   2. ������ �� 2.
// ������ ������� ����������� ����� �� ������ �� 1, ������ ����������� ��� � 2 ����.�������
// ���������� ��������, ������� ����� 3 ����������� � ����� 20 :
//   �.� �������������� �������.
//   b. * � �������������� ��������.
//
// === ����� ������� ������������� �����, ������� (3 � 20) �� ������ ������ � ���������, �
// === ���������� � ����������, �� ����� ��������

// � �������������� �������
int Calc1(int min, int max)
{
	// ������� ��������
	int result = 0;
	// ������������ ���������� ������ (����� ��� ��� +1)
	int count = max - min;
	// ��������� ������ ��� ������������ ������ ������
	int* commands;
	commands = (int*)malloc(count * sizeof(int));
	// ������������� ������� - ��� ������� �1 (+1)
	for (int i = 0; i < count; i++)
	{
		commands[i] = 1;
		result++;
	}
	// ������� ��������� ��������� (��� ������� = *2)
	boolean flagEnd;

	do
	{
		// ������� "�� ���������", ���� ���� �� ���������, ������ ��������� ��������
		flagEnd = TRUE;

		// �����, ��� ������� ����������� ��������
		int num = min;

		// ��������� � �������� ���������� ������ ������
		commands[0] += 1;

		for (int i = 0; i < count - 1; i++)
		{
			// ��������� ��������� ������������������ ������
			if (commands[i] > 2)
			{
				commands[i] = 1;
				commands[i + 1] += 1;
			}
			// ���������� �������� ��� ������ � ������������ � ���������

			if (commands[i] == 1)
			{
				num += 1;
				// ����������� ������� +1, ������, �� ��� �������� ������ ���������
				flagEnd = FALSE;
			}
			else if (commands[i] == 2)
			{
				num *= 2;
			}
			// �������� �� ���������� �������� max
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

// � �������������� ��������
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

	printf("������ 03 (����������� \"�����������\")\n\n");

	printf("���������� ��������� �������� �������������� ����� %d � %d:\n", min, max);
	printf(" - � �������������� �������: %d\n", Calc1(min, max));
	printf(" - � �������������� ��������: %d\n", Calc2(min, max));

	pause();
}
