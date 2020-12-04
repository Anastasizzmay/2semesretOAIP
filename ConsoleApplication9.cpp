// ConsoleApplication9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	int k, e, x, a, d, n, f, s;
	d = 1;
	do {
		e = 1;
		do {
			cout << "Press 1 to use recurrent solution method, press 2 to use nun recurrent solution method" << endl;
			cin >> k;
			if (k == 1 || k == 2) e = 2;

		} while (e == 1);

		switch (k)
		{
		case 1:
		{
			cout << "Enter the numder a:" << endl;
			cin >> a;
			cout << "Enter the numder n:" << endl;
			cin >> n;
			x = (1. / 2)*(1 + a);
			f = x;
			s = f;
			for (int i = 1; i < n; i++)
			{
				x = (1. / 2) * (f + (a / f));
				s += x;
				f = x;
			}
			cout << "Result: " << s << endl;
		}
		break;
		case 2:
		{
			cout << " Enter the numder a:" << endl;
			cin >> a;
			x = sqrt(a);
			cout << "Result: " << x << endl;
		}
		break;
		}
		cout << "Press 1 to repeat!" << endl;
		cin >> d;
	} while (d == 1);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
