//                          ����.�������� - ��������������� ���������������� �� C++.
//                                  ������ 4. ���������� ����������.
//                                       �������� ������� �2.
// �������:
// 1. �������� ����� Circle (����������):
// ���������� ����� ������������� ���������;
//    - �������� �� ��������� �������� ���� ����������� (�������� == );
//    - ��������� ���� ���� ����������� (�������� > ).
//    - ���������������� ��������� �������� ����������, ����� ��������� �� ������� (�������� += � -= ).
# include <iostream>
# include <Windows.h>
using namespace std;
class Circle
{
	const double PI = 3.1415926535897;  // ����� ��
	double r;                           // ������
	double circuit;                     // ����� ����������
public:
	Circle()                            // ����������� �� ��������� 
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
	bool operator==(Circle obj) // ������������� �������� == (�������� �� ��������� �������� ���� �����������(�������� == ));
	{
		obj.circuit = NULL;   // � 0 ��� ������������ ������
		if (r == obj.r) return true;
		else return false;
	}
	bool operator>(Circle obj) // ������������� �������� > (��������� ���� ���� �����������(�������� > ));
	{
		if (circuit - obj.circuit > 1e-6) return true;
		else return false;
	}
	double count_circuit(double radius) {
		circuit = 2 * PI * radius;
		return circuit;
	}
	Circle operator+=(Circle obj) // ������������� �������� += (���������������� ��������� �������� ����������, ����� ��������� �� ������� (�������� += ));
	{
		r += obj.r;
		circuit = 2 * PI*r;
		return *this;
	}
	Circle operator-=(Circle obj) // ������������� �������� -= (���������������� ��������� �������� ����������, ����� ��������� �� ������� (�������� -= ));
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
void quit() {                                         // ������� ������
	cout << "���������� ������!\n";
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
		cout << "1 - �������� �� ��������� �������� ���� ����������� (�������� == )\n";
		cout << "2 - ��������� ���� ���� ����������� (�������� > )\n";
		cout << "3 - ���������������� ��������� �������� ����������, ����� ��������� �� ������� (�������� +=)\n";
		cout << "4 - ���������������� ��������� �������� ����������, ����� ��������� �� ������� (�������� -=)\n";
		cout << "0 - �����\n";
		cout << "��� �����: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "\n������� ������ 1 ����������:\nr1 = ";
			cin >> r;
			C1.set_r(r);
			cout << "������� ������ 2 ����������:\nr2 = ";
			cin >> r;
			C2.set_r(r);
			if(C1==C2) cout << "������� C1 == C2 �����������. ������� 1 � 2 ���������� �����\n";
			else cout << "������� C1 == C2 �� �����������. ������� �� �����\n";
			system("pause");
			break;
		case 2:
			cout << "\n������� ������ 1 ����������:\nr1 = ";
			cin >> r;
			C1.set_r(r);
			cout << "������� ������ 2 ����������:\nr2 = ";
			cin >> r;
			C2.set_r(r);
			C1.count_circuit(C1.get_r());
			C2.count_circuit(C2.get_r());
			if (C1 > C2) cout << "������� C1 > C2 �����������. ����� 1 ���������� ������ ����� 2 ����������\n";
			else cout << "������� C1 > C2 �� �����������. ����� 1 ���������� ����� ��� ������ ����� 2 ����������\n";
			system("pause");
			break;
		case 3:
			cout << "\n������� ������ 1 ����������:\nr1 = ";
			cin >> r;
			C1.set_r(r);
			cout << "������� ������ 2 ����������:\nr2 = ";
			cin >> r;
			C2.set_r(r);
			C1.count_circuit(C1.get_r());
			C2.count_circuit(C2.get_r());
			cout << "\n����� ����������� �� �������� �1+=�2:\ncircuit1 = " << C1.get_circuit() << "\ncircuit2 = " << C2.get_circuit() << endl;
			cout << "\n��������� ������� ��������...(C1+=C2)" << endl;
			C1 += C2;
			cout << "\n����� ����������� ����� �������� �1+=�2:\ncircuit1 = " << C1.get_circuit() << "\ncircuit2 = " << C2.get_circuit() << endl;
			system("pause");
			break;
		case 4:
			cout << "\n������� ������ 1 ����������:\nr1 = ";
			cin >> r;
			C1.set_r(r);
			cout << "������� ������ 2 ����������:\nr2 = ";
			cin >> r;
			C2.set_r(r);
			C1.count_circuit(C1.get_r());
			C2.count_circuit(C2.get_r());
			cout << "\n����� ����������� �� �������� �1-=�2:\ncircuit1 = " << C1.get_circuit() << "\ncircuit2 = " << C2.get_circuit() << endl;
			cout << "\n�������� ������� ��������...C1-=C2" << endl;
			C1 -= C2;
			cout << "\n����� ����������� ����� �������� �1-=�2:\ncircuit1 = " << C1.get_circuit() << "\ncircuit2 = " << C2.get_circuit() << endl;
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