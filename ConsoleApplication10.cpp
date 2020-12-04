// ConsoleApplication10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<ctime>
using namespace std;
struct Stack
{
	int enfa;
	Stack* nastupni;
} *nachalo;
Stack* InStack(Stack*, int);
void View(Stack*);
void Dell_All(Stack**);
int Find_Max(Stack*);
Stack* New_Stack(Stack*, int, int);
Stack* Out_Stack(Stack*, int*);
void Go_To_Hell(int );


int main()
{
	int in, k = 0, i, n, pruv, pruv2;
	pruv = 1;
	while (pruv == 1)
	{
		Go_To_Hell(k);
		cout << "Press 1 to continue!" << endl;
		cin >> pruv;
	}
}
     void Go_To_Hell(int k)
     {
		 int g = 0, pruv, pruv2, in, n ,i;
		 while (g == 0) {
			 cout << " Press 1 to fill the stack " << endl << " Press 2 to view stack" << endl << " Press 3 to delete stack " << endl << "Press 4 to sort" << endl;
			 cin >> k;
			 switch (k)
			 {
			 case 1:
				 cout << "Enter n" << endl;
				 cin >> n;
				 srand(time(0));
				 for (i = 1; i <= n; i++)
				 {
					 cin >> in;
					 nachalo = InStack(nachalo, in);
				 }
				 break;

			 case 2:
					 View(nachalo);
				 break;
			 case 3:
					 Dell_All(&nachalo);
				 break;
			 case 4:
				 for (i = 1; i <= n; i++)
				 {
					 pruv2 = -100;
					 if (pruv2 < Find_Max(nachalo))
						 pruv = Find_Max(nachalo);
				 }
				 cout << pruv << endl;
				int d = 1;
				nachalo = New_Stack(nachalo, pruv, d);
			    View(nachalo);
				 break;
			 }
		 }
	 }

	Stack* Out_Stack(Stack * p, int* out)
	{
			//Stack* t = p;
			*out = p->enfa;
			p = p->nastupni;
			//delete t;
			return p;
	}

	Stack* New_Stack(Stack * p, int in, int d)
	{
		int inf;
		Stack* new_p = NULL;
		if (d == 0) return new_p;
		else {
			//Stack* new_p = NULL;
			p = Out_Stack(p, &inf);
			while (inf!= in)
			{
				p = Out_Stack(p, &inf);
				new_p = InStack(new_p, inf);
			}
			New_Stack(new_p, in, d-1);
		}
		return new_p;
	}

	Stack* InStack(Stack * p, int in)
	{
		Stack* t = new Stack;
		t->enfa = in;
		t->nastupni = p;
		return t;
	}

	void View(Stack * p)
	{
		Stack* t = p;
		while (t != NULL)
		{
			cout << t-> enfa << endl;
			t = t-> nastupni;
		}
		cout << endl;
	}

	void Dell_All(Stack * *p)
	{
		Stack* t;
		while (*p != NULL)
		{
			t = *p;
			*p = (*p)->nastupni;
			delete t;
		}
	}

	int Find_Max(Stack* p)
	{
		int k = -100;
		Stack* t = p;
		while (t != NULL)
		{
			if (t->enfa > k)
			k = t->enfa;
			t = t->nastupni;
		}
		return k;
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
