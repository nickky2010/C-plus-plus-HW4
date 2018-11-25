//                          Курс.Объектно - ориентированное программирование на C++.
//                                  Модуль 4. Перегрузка операторов.
//                                       Домашнее задание №1.
// 1. Создайте класс Date, который будет содержать информацию о дате(день, месяц, год).
// С помощью механизма перегрузки операторов, определите операцию разности двух дат
// (результат в виде количества дней между датами), а также операцию увеличения даты на определённое количество дней.
#include <iostream>
#include <Windows.h>
using namespace std;
class date
{
public:
	int Year, Month, Day;
	date *d2=NULL;
	date() {}
	date(int dd, int mm, int yy) 
	{
		Day = dd; Month = mm; Year = yy;
	}
	~date() 
	{ 
		if (d2 != NULL) delete d2; 
	}
	bool Less(const date &d1, const date &d2)
	{
		return (d1, d2, "");
	}
	//возвращает true если d1 раньше d2.
	//p - это строка с параметрами, указывающими какие поля структур не следует использовать при сравнении
	bool Less(const date &d1, const date &d2, char *p)
	{
		size_t end = strlen(p);
		if (d1.Year < d2.Year && !find(p, p + end, '.'))return true;
		if (d1.Month < d2.Month && !find(p, p + end, '.'))return true;
		if (d1.Day < d2.Day && !find(p, p + end, '.'))return true;
		return false;
	}
	//функция возвращает количество дней между датами
	int operator-(date d2)
	{
		date d1(*this);
		//если d2 раньше d1 поменять их местами, это сделано потому что
		//далее в функции весь код адекватен при условии что d1 раньше d2.
		if (Less(d1, d2)) { 
			swap(d2, d1); 
		};
		//разница между датами в днях
		int diff = 0;
		//между какими месяцами будем считать
		int from = d1.Month, to = d2.Month;
		//разница между годами в годах
		int diffyear = abs(d2.Year - d1.Year);
		//сколько дней между датами прошло, считая только по месяцам
		if (diffyear == 0)
			for (int i = from; i < to; i++)
			{
				switch (i)
				{
				case 1:diff += 31; break;
				case 2:diff += 28; break;
				case 3:diff += 31; break;
				case 4:diff += 30; break;
				case 5:diff += 31; break;
				case 6:diff += 30; break;
				case 7:diff += 31; break;
				case 8:diff += 31; break;
				case 9:diff += 30; break;
				case 10:diff += 31; break;
				case 11:diff += 30; break;
				case 12:diff += 31; break;
				}
			}
		else
		{
			for (int i = from; i <= 12; i++)
			{
				switch (i)
				{
				case 1:diff += 31; break;
				case 2:diff += 28; break;
				case 3:diff += 31; break;
				case 4:diff += 30; break;
				case 5:diff += 31; break;
				case 6:diff += 30; break;
				case 7:diff += 31; break;
				case 8:diff += 31; break;
				case 9:diff += 30; break;
				case 10:diff += 31; break;
				case 11:diff += 30; break;
				case 12:diff += 31; break;
				}
			}
			for (int i = 1; i < to; i++)
			{
				switch (i)
				{
				case 1:diff += 31; break;
				case 2:diff += 28; break;
				case 3:diff += 31; break;
				case 4:diff += 30; break;
				case 5:diff += 31; break;
				case 6:diff += 30; break;
				case 7:diff += 31; break;
				case 8:diff += 31; break;
				case 9:diff += 30; break;
				case 10:diff += 31; break;
				case 11:diff += 30; break;
				case 12:diff += 31; break;
				}
			}
		}
		//коррекция по дням
		diff -= d1.Day;
		diff += d2.Day;
		//сколько лет прошло между датами
		diff += ((diffyear > 1) ? (diffyear - 1) : (0)) * 365;
		//сколько было высокосных лет в промежутке между датами
		if (d2.Year <= d1.Year) {
			for (int i = d2.Year; i <= d1.Year; i++) {
				if (i % 4 == 0) diff++;
			}
		}
		if (d1.Year < d2.Year) {
			for (int i = d1.Year; i <= d2.Year; i++) {
				if (i % 4 == 0) diff++;
			}
		}
		return diff;
	}
	date operator+(int day)
	{
		date d1(*this);
		d2 = new date;
		d2->Day = Day;
		d2->Month = Month;
		d2->Year = Year;		
		bool m = true;
		int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		for (int i = 0; i < 12; i++) {
			if (i!=1&&i<11) {
				if (d2->Month == i+1 && Day + day > month[i] && m) {
					day -= month[i] - Day; d2->Month++; m = false;
				}
				if (d2->Month == i + 1 && Day + day <= month[i] && m) {
					d2->Day = Day + day; break;
				}
				if (d2->Month == i + 1 && day > month[i] && !m) {
					day -= month[i]; d2->Month++;
				}
				if (d2->Month == i + 1 && day <= month[i] && !m) {
					d2->Day = day; break;
				}
			}
			if (i == 1) {
				if (d2->Year%4==0) { month[1] = 29; }
				if (d2->Month == i + 1 && Day + day > month[i] && m) {
					day -= month[i] - Day; d2->Month++; m = false;
				}
				if (d2->Month == i + 1 && Day + day <= month[i] && m) {
					d2->Day = Day + day; break;
				}
				if (d2->Month == i + 1 && day > month[i] && !m) {
					day -= month[i]; d2->Month++;
				}
				if (d2->Month == i + 1 && day <= month[i] && !m) {
					d2->Day = day; break;
				}
				month[1] = 28;
			}
			else {
				if (d2->Month == i + 1 && Day + day > month[i] && m) {
					day -= month[i] - Day; d2->Month = 1; d2->Year++; m = false; i = -1;
				}
				if (d2->Month == i + 1 && Day + day <= month[i] && m) {
					d2->Day = Day + day; break;
				}
				if (d2->Month == i + 1 && day > month[i] && !m) {
					day -= month[i]; d2->Month = 1; d2->Year++; i = -1;
				}
				if (d2->Month == i + 1 && day <= month[i] && !m) {
					d2->Day = day; break;
				}
			}
		}
		return *d2;
	}
};
ostream &operator<<(ostream &out, const date &d)
{
	out << d.Day << '.' << d.Month << '.' << d.Year;
	return out;
}
istream &operator>>(istream &in, date &d)
{
	char c;
	in >> d.Day;
	in >> c;
	if (c == '.')
	{
		in >> d.Month;
		in >> c;
		if (c == '.') in >> d.Year;
		else cout << "неправильный формат даты, отсутствует '.' после месяца\n";
	}
	else cout << "неправильный формат даты, отсутствует '.' после года\n";
	return in;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	date D1, D2;
	int n;
	cout << "Введите первую дату в формате число.месяц.год (23.04.2018): ";
	cin >> D1;
	cout << "Введите вторую дату в формате число.месяц.год (23.05.2018): ";
	cin >> D2;
	cout << "Первая дата " << D1 << ", вторая дата " << D2 << "\n";
	cout << "Разница дат = " << D1 - D2 << "\n";
	cout << "\n\nВведите начальную дату в формате число.месяц.год (23.04.2018): ";
	cin >> D1;
	cout << "Введите количество дней: ";
	cin >> n;
	cout << "Начальная дата " << D1 << ", + количество дней = " << n << "\n";
	cout << "Новая дата = " << D1 + n << "\n";
	system("pause");
	return 0;
}
