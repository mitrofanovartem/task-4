#include <locale>
#include <iostream>
const double PI = 3.141592653589793;
using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
	setlocale(LC_ALL, "rus");
	while (1)
	{
		int z = 0;
		cout << "������� �������� 1 ������ , 0 �����: ";
		cin >> z;
		if (z != 1)
			break;
		cout << "���������� �������� ������� arccos(x)\n\n";
		double x; // �������� ���������
		double func; // ������ �������� �������
		double sum; // �������� ��������� �����
		int n; // ����� ��������� � ��������� �����

		cout << "������� 1" << endl;
		cout << "������� �������� ���������( -1 �� 1)" << endl;
		cin >> x;
		if (x > 1 or x < -1)
		{
			cout << "�������� �������� ���������" << endl;
		}
		else
		cout << "������� ����� ��������� > ";
		cin >> n;
		func = acos(x);// ���������� "�������" ��������
		double last;
		sum = sumN(x, n, last);
		cout << "������ �������� ������� ����� " << func << endl;
		cout << "��������� ����� ���� ����� " << sum << endl;
		cout << "���������� ����������� ����� " << fabs(func - sum) << endl;
		cout << "��������� ��������� ����� " << last << endl;

		cout << "\n������� 2" << endl;
		double E;
		cout << "������� �������� ��������� > ";
		cout << "������� �������� ���������( -1 �� 1)" << endl;
		cin >> x;
		if (x > 1 or x < -1)
		{
			cout << "�������� �������� ���������" << endl;
		}
		else
		cout << "������� �������� ���������� > ";
		cin >> E;
		func = sin(x);// ���������� "�������" ��������
		sum = sumE(x, E, n);
		cout << "������ �������� ������� ����� " << func << endl;
		cout << "��������� ����� ���� c �������� ��������� ����� " << sum << endl;
		cout << "������ " << n << " ������ ����" << endl;
		sum = sumE(x, E / 10, n);
		cout << "��������� ����� ���� c ���������, ������� � 10 ���, ����� " << sum << endl;
		cout << "������ " << n << " ������ ����" << endl;

	}
	
	return 0;
}

double sumN(double x, int n, double& last)
{
	// ������������� ���������� last
	last = x;
	double sum = last;
	for (int i = 1; i < n; ++i)
	{
		double r; 
	   // ���������� �������� r
		r = (2 * i - 1) * (-x * x) / (2 * i)*(2 * i + 1);
		last *= r;
		sum += last;
	}
	sum = (PI / 2) + sum;
	return sum;
}

double sumE(double x, double E, int& n)
{
	double last;
	// ������������� ���������� last
	last = x;
	double sum = last;
	for (n = 1; fabs(last) > E; ++n)
	{
		double r; 
	  // ���������� �������� r
		r = (2 * n - 1) * (-x * x) / (2 * n) * (2 * n + 1);
		last *= r;
		sum += last;
	}
	sum = (PI / 2) + sum;
    return sum;
}
