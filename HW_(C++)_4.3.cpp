//                          Курс.Объектно - ориентированное программирование на C++.
//                                  Модуль 4. Перегрузка операторов.
//                                       Домашнее задание №2.
// Задания:
// 1. Создайте класс Circle (окружность):
// Реализуйте через перегруженные операторы;
//    - Проверка на равенство радиусов двух окружностей (операция == );
//    - Сравнения длин двух окружностей (операция > ).
//    - Пропорциональное изменение размеров окружности, путем изменения ее радиуса (операция += и -= ).
# include <iostream>
# include <Windows.h>
using namespace std;
class Circle
{
	const double PI = 3.1415926535897;  // число пи
	double r;                           // радиус
	double circuit;                     // длина окружности
public:
	Circle()                            // конструктор по умолчанию 
	{            
		r = 0;
		circuit = 0;
	}
	Circle(double radius)
	{
		r = radius;
		circuit = 2 * PI*r;
	}
	~Circle() 
	{ 
	}
	bool operator==(Circle obj) // перегруженный оператор == (Проверка на равенство радиусов двух окружностей(операция == ));
	{
		obj.circuit = NULL;   // в 0 для освобождения памяти
		if (r == obj.r) return true;
		else return false;
	}
	bool operator>(Circle obj) // перегруженный оператор > (Сравнение длин двух окружностей(операция > ));
	{
		if (circuit - obj.circuit > 1e-6) return true;
		else return false;
	}
	double count_circuit(double radius) {
		circuit = 2 * PI * radius;
		return circuit;
	}
	Circle operator+=(Circle obj) // перегруженный оператор += (Пропорциональное изменение размеров окружности, путем изменения ее радиуса (операция += ));
	{
		r += obj.r;
		circuit = 2 * PI*r;
		return *this;
	}
	Circle operator-=(Circle obj) // перегруженный оператор -= (Пропорциональное изменение размеров окружности, путем изменения ее радиуса (операция -= ));
	{
		r -= obj.r;
		circuit = 2 * PI*r;
		return *this;
	}
	double get_r() {
		return r;
	}
	double get_circuit() {
		return circuit;
	}
	void set_r(double radius) {
		r = radius;
	}
	double set_circuit(double circ) {
		circuit = circ;
	}
};
void quit() {                                         // функция выхода
	cout << "Завершение работы!\n";
	system("pause");
	exit(0);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Circle C1, C2;
	double r;
	int a = -1;
	while (a) {
		int menu = -1;
		system("cls");
		cout << "1 - Проверка на равенство радиусов двух окружностей (операция == )\n";
		cout << "2 - Сравнения длин двух окружностей (операция > )\n";
		cout << "3 - Пропорциональное изменение размеров окружности, путем изменения ее радиуса (операция +=)\n";
		cout << "4 - Пропорциональное изменение размеров окружности, путем изменения ее радиуса (операция -=)\n";
		cout << "0 - выход\n";
		cout << "Ваш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "\nВведите радиус 1 окружности:\nr1 = ";
			cin >> r;
			C1.set_r(r);
			cout << "Введите радиус 2 окружности:\nr2 = ";
			cin >> r;
			C2.set_r(r);
			if(C1==C2) cout << "Условие C1 == C2 выполняется. Радиусы 1 и 2 окружности равны\n";
			else cout << "Условие C1 == C2 не выполняется. Радиусы не равны\n";
			system("pause");
			break;
		case 2:
			cout << "\nВведите радиус 1 окружности:\nr1 = ";
			cin >> r;
			C1.set_r(r);
			cout << "Введите радиус 2 окружности:\nr2 = ";
			cin >> r;
			C2.set_r(r);
			C1.count_circuit(C1.get_r());
			C2.count_circuit(C2.get_r());
			if (C1 > C2) cout << "Условие C1 > C2 выполняется. Длина 1 окружности больше длины 2 окружности\n";
			else cout << "Условие C1 > C2 не выполняется. Длина 1 окружности равна или меньше длины 2 окружности\n";
			system("pause");
			break;
		case 3:
			cout << "\nВведите радиус 1 окружности:\nr1 = ";
			cin >> r;
			C1.set_r(r);
			cout << "Введите радиус 2 окружности:\nr2 = ";
			cin >> r;
			C2.set_r(r);
			C1.count_circuit(C1.get_r());
			C2.count_circuit(C2.get_r());
			cout << "\nДлины окружностей до операции С1+=С2:\ncircuit1 = " << C1.get_circuit() << "\ncircuit2 = " << C2.get_circuit() << endl;
			cout << "\nСлаживаем радиусы объектов...(C1+=C2)" << endl;
			C1 += C2;
			cout << "\nДлины окружностей после операции С1+=С2:\ncircuit1 = " << C1.get_circuit() << "\ncircuit2 = " << C2.get_circuit() << endl;
			system("pause");
			break;
		case 4:
			cout << "\nВведите радиус 1 окружности:\nr1 = ";
			cin >> r;
			C1.set_r(r);
			cout << "Введите радиус 2 окружности:\nr2 = ";
			cin >> r;
			C2.set_r(r);
			C1.count_circuit(C1.get_r());
			C2.count_circuit(C2.get_r());
			cout << "\nДлины окружностей до операции С1-=С2:\ncircuit1 = " << C1.get_circuit() << "\ncircuit2 = " << C2.get_circuit() << endl;
			cout << "\nОтнимаем радиусы объектов...C1-=C2" << endl;
			C1 -= C2;
			cout << "\nДлины окружностей после операции С1-=С2:\ncircuit1 = " << C1.get_circuit() << "\ncircuit2 = " << C2.get_circuit() << endl;
			system("pause");
			break;
		case 0:
			quit();
			break;
		default:
			while (cin.get() != '\n');
			cout << "Неверно! Повторите ввод!\n";
		}
	}
	system("pause");
	return 0;
}