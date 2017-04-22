#include <fstream> 
#include <iostream> 
#include <queue>
using namespace std;
int main()
{
	ofstream f;
	f.open("live.txt");
	queue<int> que1;
	queue<int> que2;
	queue<int> que3;
	int p1 = 0;
	int p2 = 0;
	int variant = 0;
	int x = 0;
	int s = 0;
	setlocale(LC_ALL, "Russian");
	while (s == 0)
	{
		cout << "Нажмите \n 1. чтобы внести элемент в первую очередь \n 2. чтобы внести элемент во вторую очередь \n 3. чтобы вытолкнуть элемент из первой очереди \n 4. чтобы вытолкнуть элемент из второй очереди \n 5. чтобы показать элементы первой очереди \n 6. чтобы показать элементы второй очереди \n 7. слияние \n 8. выход \n 9. для вывода очередей " << endl;
		cin >> variant;
		switch (variant)
		{
		case 1:
			system("cls");
			cout << "Введите число" << endl;
			cin >> p1;
			que1.push(p1);
			break;

		case 2:
			system("cls");
			cout << "Введите число" << endl;
			cin >> p2;
			que2.push(p2);
			break;

		case 3:
			system("cls");
			if (que1.empty() == true)
			{
				cout << "Первая очередь пуста" << endl;
			}
			else
			{
					que1.pop();
			}
			break;

		case 4:
			system("cls");
			if (que2.empty() == true)
			{
				cout << "Вторая очередь пуста" << endl;
			}
			else
			{
					que2.pop();
			}
			break;
		case 5:
			system("cls");
			if (que1.empty() == true)
			{
				cout << "Первая очередь пуста" << endl;
			}
			else
			{	
				cout << "Элементы первой очереди" << endl;
				que3 = que1;
				while (!que3.empty())
				{
					cout << que3.front() << " ";
					que3.pop();
				}
				cout << endl;
			}
			break;
		case 6:
			system("cls");
			if (que2.empty() == true)
			{
			cout << "Вторая очередь пуста" << endl;
			}
			else
			{
				que3 = que2;
				cout << "Элементы второй очереди" << endl;
				while (!que3.empty())
				{
					cout << que3.front() << " ";
					que3.pop();
				}
				cout << endl;
			}
			break;
		case 7:
			cout << "Сколько элементов убрать?" << endl;
			cin >> x;
			if (x < que1.size())
			{
				for (int i = 0; i < x; i++)
					que1.pop();
				while (!que2.empty())
				{
					que1.push(que2.front());
					que2.pop();
				}
			}
			else
				cout << "Ошибка" << endl;
			break;

		case 8:
			s = 1;
			break;

		case 9:
			system("cls");
			if (que1.empty() == true)
			{
				cout << "Первая очередь пуста" << endl;
				f << "Первая очередь пуста" << endl;
			}
			else
			{
				cout << "Элементы первой очереди" << endl;
				que3 = que1;
				while (!que3.empty())
				{
					cout << que3.front() << " ";
					f << que3.front() << " ";;
					que3.pop();
				}
				cout << endl;
				f << endl;
			}
			if (que2.empty() == true)
			{
				cout << "Вторая очередь пуста" << endl;
				f << "Вторая очередь пуста" << endl;
			}
			else
			{
				cout << "Элементы второй очереди" << endl;
				que3 = que2;
				while (!que3.empty())
				{
					cout << que3.front() << " ";
					f << que3.front() << " ";
					que3.pop();
				}
				cout << endl;
				f << endl;
			}
			break;
		default:
				   cout << "Ошибка" << endl;
				   break;
		}
	}
	f.close();
	cout<< "Программа завершена. Результат сохранен" << endl;
}