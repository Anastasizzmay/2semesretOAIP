#include <iostream>

using namespace std;

struct tree
{
	int info;
	tree* left, * right;
};

tree* list(int);
tree* addToTree(tree*, int);
tree* deleteElementTree(tree*, int);
void menu(tree*);
void makeBlnsTree(tree**);
void makeBlns(tree**, int, int, int*);
void viewTree(tree*, int);
void countLeafes(tree*, int&);
void deleteTree(tree*);

int main()
{
	setlocale(0, "");
	tree* root = NULL;
	menu(root);
	return 0;
}

void menu(tree* root)
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TREE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	while (true)
	{
		cout << "\n1)Создание обычного дерева\n2)Создание балансированного дерева\n3)Добавление одного элемента в дерево";
		cout << "\n4)Просмотр\n5)Удаление по ключу\n6)Подсчёт листьев на каждом уровне\n7)Удаление дерева\n8)Выход" << endl;
		cout << "Выбор:> ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int temp, number;
			cout << endl << "Количество элементов в дереве:> ";
			cin >> number;
			for (int i = 0; i < number; i++)
			{
				cout << "Введите элемент № " << i + 1 << ": ";
				cin >> temp;
				root = addToTree(root, temp);
			}
			break;
		}
		case 2:
		{
			makeBlnsTree(&root);
			break;
		}
		case 3:
		{
			int temp;
			cout << endl << "Введите значение для нового элемента:> ";
			cin >> temp;
			root = addToTree(root, temp);
			break;
		}
		case 4: viewTree(root, 0); break;
		case 5:
		{
			int temp;
			cout << endl << "Введите ключ для поиска:> ";
			cin >> temp;
			root = deleteElementTree(root, temp);
			break;
		}
		case 6:
		{
			int temp = 0;
			countLeafes(root, temp);
			break;
		}
		case 7:
		{
			deleteTree(root);
			root = NULL;
			break;
		}
		case 8: return;
		default: cout << "Неверное действие!" << endl;
		}
	}
}

tree* list(int data)
{
	tree* temp = new tree;
	temp->info = data;
	temp->left = temp->right = NULL;
	return temp;
}

tree* addToTree(tree* root, int data)
{
	if (root == NULL)
	{
		tree* temp = new tree;
		temp->info = data;
		temp->left = temp->right = NULL;
		return temp;
	}
	tree* previous = NULL, * temp;
	bool find = true;
	temp = root;
	while (temp && find)
	{
		previous = temp;
		if (data == temp->info)
		{
			find = false;
			cout << "Dublucate info" << endl;
		}
		else
		{
			if (data < temp->info) temp = temp->left;
			else temp = temp->right;
		}
	}
	if (find)
	{
		temp = list(data);
		if (temp->info < previous->info)
			previous->left = temp;
		else
			previous->right = temp;
	}
	return root;
}

void viewTree(tree* root, int level)
{
	if (root)
	{
		viewTree(root->right, level + 1);
		for (int i = 0; i <= level; i++) cout << "    ";
		cout << root->info << endl;
		viewTree(root->left, level + 1);
	}
}

void countLeafes(tree* root, int& counter)
{
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL)
	{
		counter++;
		cout << counter << endl;
		return;
		counter = 0;
	}
	else 
	{
		counter = 0;
		cout << counter << endl;
	}
	countLeafes(root->right, counter);
	countLeafes(root->left, counter);
}

void deleteTree(tree* root)
{
	if (root != NULL)
	{
		deleteTree(root->right);
		deleteTree(root->left);
		delete root;
	}
}

tree* deleteElementTree(tree* root, int key)
{
	tree* delKey, * prevKey, * replaceKey, * prevReplaceKey;
	delKey = root;
	prevKey = NULL;
	while (delKey != NULL && delKey->info != key)
	{
		prevKey = delKey;
		if (delKey->info > key) delKey = delKey->left;
		else delKey = delKey->right;
	}
	if (delKey == NULL)
	{
		cout << endl << "such key is not exist!" << endl;
		return root;
	}
	if (delKey->right == NULL) replaceKey = delKey->left;
	else
		if (delKey->left == NULL) replaceKey = delKey->right;
		else
		{
			prevReplaceKey = delKey;
			replaceKey = delKey->left;
			while (replaceKey->right != NULL)
			{
				prevReplaceKey = replaceKey;
				replaceKey = replaceKey->right;
			}
			if (prevReplaceKey == delKey)
				replaceKey->right = delKey->right;
			else
			{
				replaceKey->right = delKey->right;
				prevReplaceKey->right = replaceKey->left;
				replaceKey->left = prevReplaceKey;
			}
			if (delKey == root) root = replaceKey;
			else
			{
				if (delKey->info < prevKey->info)
					prevKey->left = replaceKey;
				else
					prevKey->right = replaceKey;
				cout << " Delete " << delKey->info << endl;
				delete delKey;
				return root;
			}
		}
}

void makeBlns(tree** root, int n, int k, int* array)
{
	if (n == k)
	{
		*root = NULL;
		return;
	}
	else
	{
		int m = (n + k) / 2;
		*root = new tree;
		(*root)->info = array[m];
		makeBlns(&(*root)->left, n, m, array);
		makeBlns(&(*root)->right, m + 1, k, array);
	}
}

void makeBlnsTree(tree** root)
{
	int  quantity, * array, temp;
	cout << "Введите количество элементов в сбалансированном дереве:> ";
	cin >> quantity;
	array = new int[quantity];
	for (int i = 0; i < quantity; i++)
	{
		cout << "Введите элемент №" << i + 1 << ":> ";
		cin >> array[i];
	}
	for (int i = 0; i < quantity - 1; i++)
		for (int j = i + 1; j < quantity; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	/*cout << endl;
	for (int i = 0; i < quantity; i++) cout << " " << array[i] << " ";
	cout << endl;*/
	makeBlns(root, 0, quantity, array);
	delete[] array;
	cout << endl;
}