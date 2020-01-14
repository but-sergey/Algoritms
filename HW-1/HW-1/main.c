#include<stdio.h>
#include<math.h>
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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int sel = 0;
	do
	{
		menu();
		scanf("%i", &sel);
		//sel = 6;

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
	printf("1 - ������ 01 (���)\n");
	printf("2 - ������ 02 (������������ �� 4 �����)\n");
	printf("3 - ������ 03 (����� ���������� 2 ����������)\n");
	printf("4 - ������ 04 (���������� ���������)\n");
	printf("5 - ������ 05 (����� � ������� ����)\n");
	printf("6 - ������ 06 (�������)\n");
	printf("7 - ������ 07 (������ �� ��������� �����)\n");
	printf("8 - ������ 08 (�������� � ���� �����)\n");
	printf("9 - ������ 09 (������� ����������)\n");
	printf("10 - task10\n");
	printf("11 - task11\n");
	printf("12 - task12\n");
	printf("13 - task13\n");
	printf("14 - task14\n");
	printf("\n");
	printf("0 - �����\n");
}

void pause()
{
	printf("������� <Enter> ��� �����������...");
	getch();
}

// 1. ������ ��� � ���� ��������. ���������� � ������� ������ �����
// ���� �� ������� I=m/(h*h); ��� m-����� ���� � �����������, h - ���� � ������.
//
void task01()
{
	printf("������ 01 (���)\n\n");

	double m;
	double h;
	double I;

	printf("�����, ��: ");
	scanf("%lf", &m);

	printf("����, �: ");
	scanf("%lf", &h);

	I = m / (h * h);
	printf("��� = %.2lf\n", I);

	pause();
}

// 2. ����� ������������ �� ������� �����. ������� �� ������������.
//
void task02()
{
	printf("������ 02 (������������ �� 4 �����)\n");

	int x1, x2, x3, x4;
	int max, max1, max2;
	
	printf("����� �1: ");
	scanf("%d", &x1);

	printf("����� �2: ");
	scanf("%d", &x2);

	printf("����� �3: ");
	scanf("%d", &x3);

	printf("����� �4: ");
	scanf("%d", &x4);

	max1 = (x1 > x2) ? x1 : x2;
	max2 = (x3 > x4) ? x3 : x4;
	max = (max1 > max2) ? max1 : max2;

	printf("������������ ����� = %d\n", max);

	pause();
}

// 3. �������� ��������� ������ ���������� ���� ������������� ���������� :
// a. � �������������� ������� ����������;
// b.* ��� ������������� ������� ����������.
//
void task03()
{
	printf("������ 03 (����� ���������� 2 ����������)\n");

	int a = 1;
	int b = 2;
	int t;

	printf("a = %d, b = %d\n", a, b);
	t = a;
	a = b;
	b = t;
	printf("a = %d, b = %d\n", a, b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a = %d, b = %d\n", a, b);
	a = a * b;
	b = a / b;
	a = a / b;
	printf("a = %d, b = %d\n", a, b);
	a = a ^ b;
	b = b ^ a;
	a = a ^ b;
	printf("a = %d, b = %d\n", a, b);

	pause();
}

// 4. �������� ��������� ���������� ������ ��������� ����������� ���������.
//
void task04()
{
	printf("������ 04 (���������� ���������)\n");
	double a, b, c;
	double D, x1, x2;

	printf("a*x^2 + b*x + c = 0\n");
	
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("c = ");
	scanf("%lf", &c);

	if (a == 0)
	{
		if (b == 0)
		{
			printf("��� �� ���������, a ��� b �� ������ ��������� 0.\n");
		}
		else
		{
			x1 = -c / b;
			printf("�������� ���������, x = %.2lf.\n", x1);
		}
	}
	else
	{
		D = b * b - 4 * a * c;
		printf("D = %.2lf\n", D);
		if (D == 0)
		{
			x1 = -b / (2 * a);
			printf("��� ���������� �����, x1 = x2 = %.2lf.\n", x1);
		}
		else if (D > 0)
		{
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			printf("��� �������������� �����: x1 = %.2lf � x2 = %.2lf.\n", x1, x2);
		}
		else
		{	// ����� ����� ���� �� ��� ��������� ����������� �����, �� ����... )))
			printf("�� ��������� �������������� ����� ��������� ������ �� �����.\n");
		}
	}

	pause();
}

// 5. � ���������� �������� ����� ������.��������� ����������, � ������
// ������� ���� �� ���������.
//
void task05()
{
	printf("������ 05 (����� � ������� ����)\n");

	int month;

	printf("����� ������: ");
	scanf("%d", &month);
	
	switch (month)
	{
	case 12:
	case 1:
	case 2: printf("��� ����.\n");
		break;
	case 3:
	case 4:
	case 5: printf("��� �����.\n");
		break;
	case 6:
	case 7:
	case 8: printf("��� ����.\n");
		break;
	case 9:
	case 10:
	case 11: printf("��� ����.\n");
		break;
	default:
		printf("�������� ����� ������.\n");
	}
	
	pause();
}

// 6. ������ ������� ��������(�� 1 �� 150 ���) � ������� ��� ������ �
// ����������� ������ ����, ����� ��� ����.
//
void task06()
{
	printf("������ 06 (�������)\n");
	
	int age;

	printf("��� �������: ");
	scanf("%d", &age);
	if ((age >= 1) && (age <= 150))
	{
		if ((age % 100 >= 11) && (age % 100 <= 14))
		{
			printf("��� %d ���.\n", age);
		}
		else
		{
			switch (age % 10)
			{
			case 1: printf("��� %d ���.\n", age);
				break;
			case 2:
			case 3:
			case 4: printf("��� %d ����.\n", age);
				break;
			default: printf("��� %d ���.\n", age);
			}
		}
	}
	else
	{
		printf("�������� �������. ������� ������ ���� �� 1 �� 150 ������������.\n");
	}

	pause();
}

// 7. � ���������� �������� �������� ���������� ���� ����� ���������
// �����(x1, y1, x2, y2).��������� ����������, ��������� ���� � ������
// ����� ��� ���.
//
void task07()
{
	printf("������ 07 (������ �� ��������� �����)\n");

	int x1, y1, x2, y2;
	
	printf("���������� ������ �1, x1-y1: ");
	scanf("%d-%d", &x1, &y1);
	printf("���������� ������ �2, x2-y2: ");
	scanf("%d-%d", &x2, &y2);

	printf("\n����� ������� �� �������, ��� ����� ������ ������ (1-1) ������ �����.\n\n");

	if ((x1 + y2) % 2 == (x2 + y2) % 2)
	{
		printf("������ ������ �����: %s.\n", ((x1 + y1) % 2 == 0) ? "������" : "�������");
	}
	else
	{
		printf("������ ������� �����. ������ �1 %s, � ������ �2 %s.\n",
					((x1 + y1) % 2 == 0) ? "�����" : "������",
					((x2 + y2) % 2 == 0) ? "�����" : "������");
	}

	pause();
}

// 8. ������ a � b � ������� �������� � ���� ����� �� a �� b.
//
void task08()
{
	printf("������ 08 (�������� � ���� �����)\n");

	int a, b;

	printf("����� a: ");
	scanf("%d", &a);
	printf("����� b: ");
	scanf("%d", &b);
	if (a <= b)
	{
		printf("    x       x^2       x^3\n\n");
		do
		{
			printf("%5d%10d%10d\n", a, a * a, a * a * a);
			a++;
		} while (a <= b);
	}
	else
	{
		printf("����� a �� ������ ���� ������, ��� ����� b");
	}

	pause();
}

// 9. ���� ����� ������������� ����� N � K. ��������� ������ ��������
// �������� � ���������, ����� ������� �� ������� ������ N �� K, �
// ����� ������� �� ����� �������.
//
void task09()
{
	printf("������ 09 (������� ����������)\n");

	int N, K;
	int Q = 0;
	int R = 0;

	printf("������� N: ");
	scanf("%d", &N);
	printf("�������� K: ");
	scanf("%d", &K);

	while (N >= K)
	{
		N -= K;
		Q++;
	}
	R = N;

	printf("\n������� Q = %d, ������� R = %d\n", Q, R);

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
