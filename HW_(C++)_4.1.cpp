//                          ����.�������� - ��������������� ���������������� �� C++.
//                                  ������ 4. ���������� ����������.
//                                       �������� ������� �1.
// 1. �������� ����� Date, ������� ����� ��������� ���������� � ����(����, �����, ���).
// � ������� ��������� ���������� ����������, ���������� �������� �������� ���� ���
// (��������� � ���� ���������� ���� ����� ������), � ����� �������� ���������� ���� �� ����������� ���������� ����.
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
	//���������� true ���� d1 ������ d2.
	//p - ��� ������ � �����������, ������������ ����� ���� �������� �� ������� ������������ ��� ���������
	bool Less(const date &d1, const date &d2, char *p)
	{
		size_t end = strlen(p);
		if (d1.Year < d2.Year && !find(p, p + end, '.'))return true;
		if (d1.Month < d2.Month && !find(p, p + end, '.'))return true;
		if (d1.Day < d2.Day && !find(p, p + end, '.'))return true;
		return false;
	}
	//������� ���������� ���������� ���� ����� ������
	int operator-(date d2)
	{
		date d1(*this);
		//���� d2 ������ d1 �������� �� �������, ��� ������� ������ ���
		//����� � ������� ���� ��� ��������� ��� ������� ��� d1 ������ d2.
		if (Less(d1, d2)) { 
			swap(d2, d1); 
		};
		//������� ����� ������ � ����
		int diff = 0;
		//����� ������ �������� ����� �������
		int from = d1.Month, to = d2.Month;
		//������� ����� ������ � �����
		int diffyear = abs(d2.Year - d1.Year);
		//������� ���� ����� ������ ������, ������ ������ �� �������
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
		//��������� �� ����
		diff -= d1.Day;
		diff += d2.Day;
		//������� ��� ������ ����� ������
		diff += ((diffyear > 1) ? (diffyear - 1) : (0)) * 365;
		//������� ���� ���������� ��� � ���������� ����� ������
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
		else cout << "������������ ������ ����, ����������� '.' ����� ������\n";
	}
	else cout << "������������ ������ ����, ����������� '.' ����� ����\n";
	return in;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	date D1, D2;
	int n;
	cout << "������� ������ ���� � ������� �����.�����.��� (23.04.2018): ";
	cin >> D1;
	cout << "������� ������ ���� � ������� �����.�����.��� (23.05.2018): ";
	cin >> D2;
	cout << "������ ���� " << D1 << ", ������ ���� " << D2 << "\n";
	cout << "������� ��� = " << D1 - D2 << "\n";
	cout << "\n\n������� ��������� ���� � ������� �����.�����.��� (23.04.2018): ";
	cin >> D1;
	cout << "������� ���������� ����: ";
	cin >> n;
	cout << "��������� ���� " << D1 << ", + ���������� ���� = " << n << "\n";
	cout << "����� ���� = " << D1 + n << "\n";
	system("pause");
	return 0;
}
