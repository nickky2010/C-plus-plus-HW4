//                          Курс.Объектно - ориентированное программирование на C++.
//                                  Модуль 4. Перегрузка операторов.
//                                       Домашнее задание №2.
// Добавить в строковый класс функцию, которая создаёт строку, содержащую пересечение двух строк, то есть общие символы для двух строк. 
// Например, результатом пересечения строк "sdqcg" "rgfas34" будет строка "sg".
// Для реализации функции перегрузить оператор * (бинарное умножение)
#include <iostream>
#include <windows.h>
using namespace std;
class String
{
private:
	char *str = NULL; char* s = NULL;   // s = 0 для определения выделения памяти при бинарном умножении и деструктора
	int N1 = 80, N2, N3;
public:
	static int num_obj_str;
	String()                      // конструктор по умолчанию
	{
		str = new char[N1 + 1];
		num_obj_str++;
	}
	String(int n)                 // конструктор, позволяющий создавать строку произвольного размера
	{
		str = new char[n + 1];
		num_obj_str++;
		N2 = n + 1;
	}
	String(const char *s)         // конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя
	{
		N3 = strlen(s) + 1;
		str = new char[N3];
		strcpy(str, s);
		num_obj_str++;
	}
	String(const String& ob)      // конструктор копии
	{
	str = new char;
	*str = *ob.str;               // значение копии
	int i = 0;
	while (ob.str[i] != '\0') {
	str[i] = ob.str[i];
	i++;
	}
	str[i] = '\0';
	num_obj_str++;
	}
	~String()                     // деструктор
	{
		if (str != NULL) delete str;
		if (s != NULL) delete s;  // если выделялась память при бинарном умножении то удаляем
		num_obj_str--;
	}
	void inter()                  // метод для ввода строк с клавиатуры по умолчанию
	{
		int i = 0;
		char c;
		while ((c = getchar()) != '\n') {
			if (i < N1) {
				str[i] = c;
				i++;
			}
		}
		str[i] = '\0';
	}
	void inter(int n)             // метод для ввода строки произвольного размера с клавиатуры 
	{
		int i = 0;
		char c;
		while (cin.get() != '\n');
		while ((c = getchar()) != '\n') {
			if (i < n) {
				str[i] = c;
				i++;
			}
		}
		str[i] = '\0';
	}
	char* operator*(String s2)
	{
		String s1(*this);
		int n, n1 = strlen(s1.str)+1;                         // считаем длину строки 1 объекта
		int n2 = strlen(s2.str) + 1;                          // считаем длину строки 2 объекта
		if (n1 >= n2) 
			n = n1;
		else 
			n = n2;
		this->s = new char[n];                                // выделяем размер по наибольшей строке
		int i = 0, k = 0;
		while (s1.str[i] != '\0') {                           // идем по строке 1 объекта
			int j = 0;
			while (s2.str[j] != '\0') {                       // идем по строке 2 объекта
				if (s1.str[i] == s2.str[j]) {                 // если символы совпадают
					if (k != 0) {                             // если ранее мы уже заносили в строку символ
						int m = k;
						while (m != 0) {                      // идем по циклу
							if (s[m - 1] != s1.str[i]) {      // и сверяем нет ли повторов
								m--;
							}
							else break;
						}
						if (m == 0) {                         // если повторов нет то записываем символ
							s[k] = s1.str[i];
							s[k+1] = '\0';
							k++;
						}
					}	
					else {
						s[k] = s1.str[i];
						k++;
					}
				}
				j++;
			}
			i++;
		}
		return s;
	}
	void show()                   // метод для вывода строки на экран
	{
		cout << str << endl;
	}
	static int show_Num_obj_str() // статическая функция-член, которая будет возвращать количество созданных объектов строк
	{
		return num_obj_str;
	}
};
int String::num_obj_str = 0;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char str1[100], str2[100], *str3;
	cout << "Введите строку для 1 объекта: \n";
	std::cin.getline(str1, 101);
	String s1(str1);
	cout << "Введите строку для 2 объекта: \n";
	std::cin.getline(str2, 101);
	String s2(str2);
	cout << "Строка 1 объекта: \n";
	s1.show();
	cout << "Строка 2 объекта: \n";
	s2.show();
	cout << "Общие символы для двух строк: \n";
	str3 = s1*s2;
	cout << str3 << endl;
	system("pause");
	return 0;
}
