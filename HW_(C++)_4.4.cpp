//                          ����.�������� - ��������������� ���������������� �� C++.
//                                  ������ 4. ���������� ����������.
//                                       �������� ������� �2.
// 2. ������� ����� Airplane (�������).
// � ������� ���������� ���������� �����������:
//   -�������� �� ��������� ����� ��������� (�������� == );
//   -���������� � ���������� ���������� � ������ �������� (�������� ++ � -- � ���������� �����);
//   -��������� ���� ��������� �� ����������� ���������� ���������� ���������� �� ����� (��������>).

#include <iostream>
#include <Windows.h>
#include <stdio.h>
using namespace std;
class Airplane
{
	char* type;           // ��� ��������
	int passenger;        // ���������� ����������
	int max_pass;         // ����������� ���������� ���������� ���������� �� �����
public:
	Airplane()                             // ����������� �� ��������� 
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
	bool operator == (const Airplane& n)  // ������������� �������� == (�������� �� ��������� ����� ��������� (�������� == ));
	{
		if (strcmp(type, n.type) == 0)
			return true;
		else
			return false;
	}
	bool operator>(Airplane obj) // ������������� �������� > (��������� ���� ��������� �� ����������� ���������� ���������� ���������� �� ����� (��������>));
	{
		if (this->max_pass > obj.max_pass) return true;
		else return false;
	}
	Airplane& operator++() // ������������� �������� ++ (���������� ���������� � ������ �������� (�������� ++ � ���������� �����));
	{
		if (this->passenger + 1 <= this->max_pass) { // ����������� ���������� ���������� ���� �� ��������� ������������ ���������������
			this->passenger = this->passenger + 1;
		}
		return *this;
	}
	Airplane& operator--() // ���������� ���������� � ������ �������� (�������� -- � ���������� �����)
	{
		if (this->passenger - 1 >= 0) {         // ��������� ���������� ���������� ���� �� ����� ����� �� ������ 0
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
		cout << "\n������� � " << i << endl;
		cout << "��� ��������: " << type << endl;
		cout << "���������� ����������: " << passenger << endl;
		cout << "����������� ��������: " << max_pass << endl;
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
void quit() {                                         // ������� ������
	cout << "���������� ������!\n";
	system("pause");
	exit(0);
}
void init_test(int i, char *type, int &max, int &pass) {
	cout << "������� ��� "<< i <<" �������� (�������� Boeing 747):\nType " << i << " = ";
	gets_s(type, 256);
	cout << "������� ����������� ��������� ���������� ���������� �� ����� " << i << " ��������:\nMax " << i << " = ";
	cin >> max;
	while (max < 0) {
		cout << "������! ����� ������ ���� �������������\n";
		cin >> max;
	}
	cout << "������� ���������� ���������� " << i << " ��������:\nPass " << i << " = ";
	cin >> pass;
	while (pass < 0 || pass > max) {
		if (pass < 0) {
			cout << "������! ����� ������ ���� �������������\n";
		}
		if (pass > max) {
			cout << "������! ���������� ���������� " << i << " �������� ��������� ����������� ��������\n";
		}
		cout << "������� ���������� ���������� " << i << " ��������:\nPass " << i << " = ";
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
		cout << "1 - �������� �� ��������� ����� ��������� (�������� == )\n";
		cout << "2 - ���������� ���������� � ������ �������� (�������� ++ � ���������� �����)\n";
		cout << "3 - ���������� ���������� � ������ �������� (�������� -- � ���������� �����)\n";
		cout << "4 - ��������� ���� ��������� �� ����������� ���������� ���������� ���������� �� ����� (��������>)\n";
		cout << "0 - �����\n";
		cout << "��� �����: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			A1.show(1);
			A2.show(2);
			if(A1==A2) cout << "������� A1 == A2 �����������. 1 � 2 ������� ����������� ����\n";
			else cout << "������� A1 == A2 �� �����������. 1 � 2 ������� ������� ����\n";
			system("pause");
			break;
		case 2:
			A1.show(1);
			A2.show(2);
			cout << "\n�� ����� ���-�� ��������� ����� ���������� � ����� ��������: ";
			cin >> index;
			for (int i = 0; i < index; i++) {
				++A1;
				++A2;
			}
			cout << "������ ����� ����������:\n";
			A1.show(1);
			A2.show(2);
			system("pause");
			break;
		case 3:
			A1.show(1);
			A2.show(2);
			cout << "\n�� ����� ���-�� ��������� ����� ���������� � ����� ��������: ";
			cin >> index;
			for (int i = 0; i < index; i++) {
				--A1;
				--A2;
			}
			cout << "������ ����� ����������:\n";
			A1.show(1);
			A2.show(2);
			system("pause");
			break;
		case 4:
			cout << "���������� ��� �������� �� ��������������� (Max 1 > Max 2):\n";
			if (A1 > A2) cout << "1 ������� �������������\n";
			else cout << "1 ������� �� ����������� ������ ��� ����� 2 ��������\n";
			system("pause");
			break;
		case 0:
			quit();
			break;
		default:
			while (cin.get() != '\n');
			cout << "�������! ��������� ����!\n";
		}
	}
	system("pause");
	return 0;
}
