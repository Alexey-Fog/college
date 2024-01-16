#include <iostream>
#include <string>
#include "Square.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
    cout << "Введите количество квадратов: ";
	int count = 0;
	Square* squares;
	while (count<1)
	{
		string a;
		cin >> a;
		try {
			count = stoi(a);
			if (count < 1) cout << "Введите количество (БОЛЬШЕ 0) квадратов: ";
		}
		catch (exception ex) {
			cout << ex.what() << endl << "Повторите ввод: " << endl;
		}
	}
	squares = new Square[count];
	system("cls");
	cout << "Создано " << count << " квадратов, укажите их стороны:" << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Сторона квадрата[" << i << "]: ";
		double side = 0;
		do
		{
			string a;
			cin >> a;
			try {
				side = stod(a);
				if (side <= 0.0) cout << "Размер стороны должен быть больше 0! Повторите ввод: ";
			}
			catch (exception ex) {
				cout << ex.what() << endl;
			}
		} while (!squares[i].setSide(side));
	}
	system("cls");
	cout << "Создание квадратов завершено!" << endl;
	do {
		cout << "Введите индекс квадрата от 0 до " << count - 1 << endl;
		int index = -1;
		do {
			string a;
			cin >> a;
			try {
				index = stoi(a);
				if (index < 0 || index >= count) cout << "Некорректный ввод! Повторите ввод: ";
			}
			catch (exception ex) {
				cout << ex.what() << endl << "Повторите ввод: " << endl;
			}
		} while (index == -1);
		cout << R"(0) выход.
1) увеличение/уменьшение размера на определённый процент.
2) вычисление периметра.
3) вычисление площади.
4) вычисление диагонали.
)";
		cout << "Введите номер команды" << endl;
		int command = -1;
		do {
			string a;
			cin >> a;
			try {
				command = stoi(a);
				if (command == 0) return 0;
				if (command < 1 || command > 4) cout << "Некорректный ввод! Повторите ввод: ";
			}
			catch (exception ex) {
				cout << ex.what() << endl << "Повторите ввод: " << endl;
			}
		} while (index == -1);
		switch (command)
		{
		case 1:
		{
			cout << "Сторона квадрата[" << index << "] равна " << squares[index].getSide() << endl;
			cout << "Введите процент, на который хотите изменить размер стороны: ";
			double proc = 0.0;
			do {
				string a;
				cin >> a;
				try {
					proc = stod(a);
					break;
				}
				catch (exception ex) {
					cout << ex.what() << endl << " Повторите ввод: " << endl;
				}
			} while (true);
			squares[index].resize(proc);
			cout << "Сторона квадрата[" << index << "] равна " << squares[index].getSide() << endl;
			break;
		}
		case 2:
			cout << "Периметр квадрата[" << index << "] равен " << squares[index].calculateP() << endl;
			break;
		case 3:
			cout << "Площадь квадрата[" << index << "] равен " << squares[index].calculateS() << endl;
			break;
		case 4:
			cout << "Диагональ квадрата[" << index << "] равна " << squares[index].calculateDiagonal() << endl;
			break;
		default:
			break;
		}
	} while (true);
	return 0;
}