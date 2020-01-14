#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:6031)

// ���� "��������� � ��������� ������"
// ������������ ������ �1
// ��� ������

void menu();
void task01();
void task02();
void task03();
void task04();
void task05();
void task06();
void task07();
void task08();
void task09();
void task10();
void task11();
void task12();
void task13();
void task14();

int main(int argc, const char* argv[])
{
	int sel = 0;
	do
	{
		menu();
		scanf("%i", &sel);
		system("cls");
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
		case 7: task07();
			break;
		case 8: task08();
			break;
		case 9: task09();
			break;
		case 10: task10();
			break;
		case 11: task11();
			break;
		case 12: task12();
			break;
		case 13: task13();
			break;
		case 14: task14();
			break;
		}
	} while (sel != 0);

	return 0;
}

void menu()
{
	system("cls");
	printf("1 - task01\n");
	printf("2 - task02\n");
	printf("3 - task03\n");
	printf("4 - task04\n");
	printf("5 - task05\n");
	printf("6 - task06\n");
	printf("7 - task07\n");
	printf("8 - task08\n");
	printf("9 - task09\n");
	printf("10 - task10\n");
	printf("11 - task11\n");
	printf("12 - task12\n");
	printf("13 - task13\n");
	printf("14 - task14\n");
	printf("\n");
	printf("0 - exit\n");
}

void pause()
{
	printf("Press <Enter> to continue...");
	getch();
}

// 1. ������ ��� � ���� ��������. ���������� � ������� ������ �����
// ���� �� ������� I=m/(h*h); ��� m-����� ���� � �����������, h - ���� � ������.
//
void task01()
{
	printf("Task 01\n");

	pause();
}

// 2. ����� ������������ �� ������� �����. ������� �� ������������.
//
void task02()
{
	printf("Task 02\n");

	pause();
}

// 3. �������� ��������� ������ ���������� ���� ������������� ���������� :
// a. � �������������� ������� ����������;
// b.* ��� ������������� ������� ����������.
//
void task03()
{
	printf("Task 03\n");

	pause();
}

// 4. �������� ��������� ���������� ������ ��������� ����������� ���������.
//
void task04()
{
	printf("Task 04\n");

	pause();
}

// 5. � ���������� �������� ����� ������.��������� ����������, � ������
// ������� ���� �� ���������.
//
void task05()
{
	printf("Task 05\n");

	pause();
}

// 6. ������ ������� ��������(�� 1 �� 150 ���) � ������� ��� ������ �
// ����������� ������ ����, ����� ��� ����.
//
void task06()
{
	printf("Task 06\n");

	pause();
}

// 7. � ���������� �������� �������� ���������� ���� ����� ���������
// �����(x1, y1, x2, y2).��������� ����������, ��������� ���� � ������
// ����� ��� ���.
//
void task07()
{
	printf("Task 07\n");

	pause();
}

// 8. ������ a � b � ������� �������� � ���� ����� �� a �� b.
//
void task08()
{
	printf("Task 08\n");

	pause();
}

// 9. ���� ����� ������������� ����� N � K. ��������� ������ ��������
// �������� � ���������, ����� ������� �� ������� ������ N �� K, �
// ����� ������� �� ����� �������.
//
void task09()
{
	printf("Task 09\n");

	pause();
}

// 10. ���� ����� ����� N(> 0). � ������� �������� ������� ������ � ������
// ������� �� ������� ����������, ������� �� � ������ ����� N �������� �����.
// ���� �������, �� ������� True, ���� ��� � ������� False.
//
void task10()
{
	printf("Task 10\n");

	pause();
}

// 11. � ���������� �������� �����, ���� �� ����� ������ 0. ���������� �������
// �������������� ���� ������������� ������ �����, �������������� �� 8.
//
void task11()
{
	printf("Task 11\n");

	pause();
}

// 12. �������� ������� ���������� ������������� �� ���� �����.
//
void task12()
{
	printf("Task 12\n");

	pause();
}

// 13. * �������� �������, ������������ ��������� ����� �� 1 �� 100.
// �) � �������������� ����������� ������� rand()
// �) ��� ������������� ����������� ������� rand()
//
void task13()
{
	printf("Task 13\n");

	pause();
}

// 14. * ����������� �����.����������� ����� ���������� �����������,
// ���� ��� ����� ��������� ������ ������ ��������.��������, 25^2 = 625.
// �������� ���������, ������� ������ ����������� ����� N � ������� ��
// ����� ��� ����������� �����, �� ������������� N.
//
void task14()
{
	printf("Task 14\n");

	pause();
}
