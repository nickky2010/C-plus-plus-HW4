//                          Курс.Объектно - ориентированное программирование на C++.
//                                  Модуль 4. Перегрузка операторов.
//                                       Домашнее задание №2.
// 2. Создать класс Airplane (самолет).
// С помощью перегрузки операторов реализовать:
//   -Проверка на равенство типов самолетов (операция == );
//   -Увеличение и уменьшение пассажиров в салоне самолета (операции ++ и -- в префиксной форме);
//   -Сравнение двух самолетов по максимально возможному количеству пассажиров на борту (операция>).

#include <iostream>
#include <Windows.h>
#include <stdio.h>
using namespace std;
class Airplane
{
	char* type;           // тип самолета
	int passenger;        // количество пассажиров
	int max_pass;         // максимально возможному количеству пассажиров на борту
public:
	Airplane()                             // конструктор по умолчанию 
	{       
		type = NULL;
		passenger = 0;
		max_pass = 0;
	}
	Airplane(char* type, int max_pas, int pas)
	{
		int len = 0;
		len = strlen(type);
		this->type = new char[len + 1];
		strcpy_s(this->type, len+1, type);
		passenger = pas;
		max_pass = max_pas;
	}
	Airplane(const Airplane& obj)
	{
		int len = 0;
		len = strlen(obj.type);
		passenger = obj.passenger;
		max_pass = obj.max_pass;
		type = new char[len + 1];
		strcpy_s(type, len+1, obj.type);
	}
	~Airplane() 
	{ 
	}
	bool operator == (const Airplane& n)  // перегруженный оператор == (Проверка на равенство типов самолетов (операция == ));
	{
		if (strcmp(type, n.type) == 0)
			return true;
		else
			return false;
	}
	bool operator>(Airplane obj) // перегруженный оператор > (Сравнение двух самолетов по максимально возможному количеству пассажиров на борту (операция>));
	{
		if (this->max_pass > obj.max_pass) return true;
		else return false;
	}
	Airplane& operator++() // перегруженный оператор ++ (Увеличение пассажиров в салоне самолета (операции ++ в префиксной форме));
	{
		if (this->passenger + 1 <= this->max_pass) { // увеличиваем количество пассажиров если не превышена максимальная вместительность
			this->passenger = this->passenger + 1;
		}
		return *this;
	}
	Airplane& operator--() // Уменьшение пассажиров в салоне самолета (операции -- в префиксной форме)
	{
		if (this->passenger - 1 >= 0) {         // уменьшаем количество пассажиров если их после этого не меньше 0
			this->passenger = this->passenger - 1;
		}
		return *this;
	}
	char* get_type() {
		return type;
	}	
	void set_type() {
		cin.ignore();
		cin.getline(type, 101);
		int n = strlen(type);
		type[n] = '\0';
	}
	void show(int i) {
		cout << "\nСамолет № " << i << endl;
		cout << "Тип самолета: " << type << endl;
		cout << "Количество пассажиров: " << passenger << endl;
		cout << "Вместимость самолета: " << max_pass << endl;
	}
	int get_passenger() {
		return passenger;
	}	
	void set_passenger() {
		int tmp;
		cin >> tmp;
		passenger = tmp;
	}
	int get_max_pass() {
		return max_pass;
	}
	void set_max_pass() {
		int tmp;
		cin >> tmp;
		max_pass = tmp;
	}
};
void quit() {                                         // функция выхода
	cout << "Завершение работы!\n";
	system("pause");
	exit(0);
}
void init_test(int i, char *type, int &max, int &pass) {
	cout << "Введите тип "<< i <<" самолета (например Boeing 747):\nType " << i << " = ";
	gets_s(type, 256);
	cout << "Введите максимально возможное количество пассажиров на борту " << i << " самолета:\nMax " << i << " = ";
	cin >> max;
	while (max < 0) {
		cout << "Ошибка! Число должно быть положительным\n";
		cin >> max;
	}
	cout << "Введите количество пассажиров " << i << " самолета:\nPass " << i << " = ";
	cin >> pass;
	while (pass < 0 || pass > max) {
		if (pass < 0) {
			cout << "Ошибка! Число должно быть положительным\n";
		}
		if (pass > max) {
			cout << "Ошибка! Количество пассажиров " << i << " самолета превышает вместимость самолета\n";
		}
		cout << "Введите количество пассажиров " << i << " самолета:\nPass " << i << " = ";
		cin >> pass;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char type_1[256];
	char type_2[256];
	int pass1, pass2;
	int index;
	int max1, max2;
	char c[2];
	int a = -1;
	init_test(1, type_1, max1, pass1);
	Airplane A1(type_1, max1, pass1);
	cin.getline(c, 2);
	cout << endl;
	init_test(2, type_2, max2, pass2);
	Airplane A2(type_2, max2, pass2);
	while (a) {
		int menu = -1;
		system("cls");
		cout << "1 - Проверка на равенство типов самолетов (операция == )\n";
		cout << "2 - Увеличение пассажиров в салоне самолета (операции ++ в префиксной форме)\n";
		cout << "3 - Уменьшение пассажиров в салоне самолета (операции -- в префиксной форме)\n";
		cout << "4 - Сравнение двух самолетов по максимально возможному количеству пассажиров на борту (операция>)\n";
		cout << "0 - выход\n";
		cout << "Ваш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			A1.show(1);
			A2.show(2);
			if(A1==A2) cout << "Условие A1 == A2 выполняется. 1 и 2 самолет одинакового типа\n";
			else cout << "Условие A1 == A2 не выполняется. 1 и 2 самолет разного типа\n";
			system("pause");
			break;
		case 2:
			A1.show(1);
			A2.show(2);
			cout << "\nНа какое кол-во увеличить число пассажиров в обоих самолётах: ";
			cin >> index;
			for (int i = 0; i < index; i++) {
				++A1;
				++A2;
			}
			cout << "Данные после увеличения:\n";
			A1.show(1);
			A2.show(2);
			system("pause");
			break;
		case 3:
			A1.show(1);
			A2.show(2);
			cout << "\nНа какое кол-во уменьшить число пассажиров в обоих самолётах: ";
			cin >> index;
			for (int i = 0; i < index; i++) {
				--A1;
				--A2;
			}
			cout << "Данные после уменьшения:\n";
			A1.show(1);
			A2.show(2);
			system("pause");
			break;
		case 4:
			cout << "Сравниваем два самолета по вместительности (Max 1 > Max 2):\n";
			if (A1 > A2) cout << "1 самолет вместительнее\n";
			else cout << "1 самолет по вместимости меньше или равен 2 самолету\n";
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
