#include <iostream>
#include <math.h>
using namespace std;

double function(double x); 
double I(double a, double b, int n, double y);
double IntegralN(double a, double b, int n);
double IntegralEps(double a, double b);

int main() {
	setlocale(0, "");
	cout << "\t\tВычисление интеграла функции (sin(x) * sin(x)-(x/5)) методом трапеции: " << endl;
	double a, b;
	int fate;
	cout << "Введите а: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	while(true)
	{ 
		cout << "Производить вычисления через введённое количество итераций - 1" << endl;
		cout << "Производить вычисления через введённую погрешность  - 2" << endl;
		cout << "Выйти - 0\nВыбор:> ";
		cin >> fate;
		switch (fate)
		{
		case 1:
		{
			int n;
			cout << "Введите n: ";
			cin >> n;
			cout << endl << "Результат: " << IntegralN(a, b, n) << endl;
			break;
		}
		case 2:
		{
			cout << endl << "Результат: " << IntegralEps(a, b) << endl;
			break;
		}
		case 0:
		{
			return 0;
			break;
		}
		default: cout << "Неверное действие!" << endl;
		}
	}
}

double function(double x)
{
	return (sin(x) * sin(x)-(x/5)); 
}

double I(double a, double b, int n, double y )
{
	return ((b - a) / (2 * n) * y);
}

double IntegralN(double a, double b, int n)
{
	double y = 0;
	double h, In = 0;
	if (n > 1) {
		h = (b - a) / n;
		y += function(a) + function(b);
		for (int i = 1; i < n; i++)
		{
			y += 2 * (function(a + h * i));
		}
		In = I(a, b, n, y);
		return In;
	}	
}

double IntegralEps(double a, double b) 
{
	double precision, In1, In2 = 0, y = 0;
	cout << endl << "Введите погрешность: ";
	cin >> precision;
	int n = 2;
	In1 = IntegralN(a, b, n);
	double temp;
	do {
		n *= 2;
		In2 = IntegralN(a, b, n);
		temp = fabs(In1 - In2);
		In1 = In2;
	} while (temp > precision);
	return In2;
}