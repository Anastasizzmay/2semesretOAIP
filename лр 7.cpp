#include <iostream> 
#include <math.h> 

using namespace std;
double Function(double);
double Method(double , double* , double* , int);
double Get();


int main()
{
	setlocale(0, "rus");
	double a, b, x;
	int i, m, n = 3;  
	cout << "\nВведите промежуток [a, b]:\n";
	cout << "\na = ";
	a = Get();
	cout << "\nb = ";
	b = Get();
	if (a > b)
	{
		double p = a;
		a = b;
		b = p;
	}
	cout << "\nВведите кол-во точек\nm = ";
	m = (int)Get();
	while (m <= 0)
	{
		cout << "\nДавай поновой " << endl;
		m = (int)Get();
	}
	double* array_of_x = new double[m];
	double* array_of_y = new double[m];
	double h = (b - a) / (m - 1);
	double h1 = (b - a) / (n - 1);
	for (x = a, i = 0; i < m; i++)
	{
		array_of_x[i] = x;
		array_of_y[i] = Function(x);
		x += h;
	}
	cout << "\n----Результат----" << endl;
	for (x = a, i = 0; i < n; i++, x += h1)
	{
		double y_t = Method(x, array_of_x, array_of_y, m);
		cout << "При x = " << x << " f*(x) = " << y_t << endl;
	}
	return 0;
}

double Function(double x)

{
	return sin(x) * sin(x) - x / 5;
}

double Method(double x, double* arr_x, double* arr_y, int m)

{
	int i;
	if (x <= arr_x[0])
		return Function(arr_x[0]);
	else 
		if (x >= arr_x[m - 1])
		return Function(arr_x[m - 1]);
	for (i = 0; i < m - 1; ++i)
		if (x == arr_x[i])
			return Function(arr_x[i]);
	for (i = 0; i < m - 1; ++i)
		if (x >= arr_x[i] && x <= arr_x[i + 2])
			return
			arr_y[i] +

			(x - arr_x[i]) * (arr_y[i + 1] - arr_y[i]) / (x - arr_x[i]) +

			(x - arr_x[i]) *

			(x - arr_x[i + 1]) /

			(arr_x[i] - arr_x[i + 2]) *

			((arr_y[i] - arr_y[i + 1]) / (arr_x[i] - arr_x[i + 1]) - (arr_y[i] - arr_x[i + 2]) / (arr_x[i + 1] - arr_x[i + 2]));

	return 0;

}

double Get()

{
	double value;
	while (true)
	{
		cin >> value;
		if (cin.get() == '\n') break;
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Попробуйте ввести значение снова :)\n= ";
		}
	}
	return value;
}

