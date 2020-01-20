// ================================================================
// ��������!!! ��� ����������� ������� ���� (� Win7) � ���� �������
// � ��������� �������� ����� �� Lucida Console!
// ================================================================

// ���� "��������� � ��������� ������"
// ������������ ������ �6
// ��� ������

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
		case 4: task04();
			break;
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	system("cls");
	printf(" 1 - ������ 01 (������� ���������)\n");
	printf(" 2 - ������ 02 (����� ����� � �������)\n");
	printf(" 3 - ������ 03 (����� ����� � ������)\n");
	printf(" 3 - ������ 04 (���������� ������� ��� ������ � �������)\n\n");
	printf(" 0 - �����\n\n");
	printf(" -=> ");
}

void pause()
{
	printf("\n������� <Enter> ��� �����������...");
	getch();
}

// 1. �������� �������, ������� ��������� ������� ��������� �� ����� � ������� �� �� �����
//
void task01()
{
	printf("������ 01 (������� ���������)\n\n");

	pause();
}

// 2. �������� ����������� ������� ������ ����� � �������.
//
void task02()
{
	printf("������ 02 (����� ����� � �������)\n\n");

	pause();
}

// 3. �������� ������� ������ ����� � ������
//
void task03()
{
	printf("������ 03 (����� ����� � ������)\n\n");

	pause();
}

// 4. *������� ���������� ������� ��� ������ � �������.
//
void task04()
{
	printf("������ 04 (���������� ������� ��� ������ � �������)\n\n");

	pause();
}
