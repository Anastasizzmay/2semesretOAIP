#include <iostream>
#include <cmath>

using namespace std;

double F(double x)
{
	return (sin(x)*sin(x)-x/5-1);
}

int main()
{
	setlocale(0, "");
	double x1, x2, res = 0, y, E;
	cout << "Вычисление по методу секущих" << endl;
	cout << "Введите погрешность:" << endl;
	cin >> E;
	cout << "Введите начало промежутка поиска решений:" << endl;
	cin >> x1;
	cout << "Введите конец промежутка поиска решений : " << endl;
	cin >> x2;
	do
	{
		y = res;
		res = x2 - ((x2 - x1) / (F(x2) - F(x1))) * F(x2);
		x1 = x2;
		x2 = res;
	} while (fabs(y - res) >= E);
	cout << "Ответ: " << res << endl;
	system("pause");
	return 0;
}