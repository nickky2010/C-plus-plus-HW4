//                          ����.�������� - ��������������� ���������������� �� C++.
//                                  ������ 4. ���������� ����������.
//                                       �������� ������� �2.
// �������� � ��������� ����� �������, ������� ������ ������, ���������� ����������� ���� �����, �� ���� ����� ������� ��� ���� �����. 
// ��������, ����������� ����������� ����� "sdqcg" "rgfas34" ����� ������ "sg".
// ��� ���������� ������� ����������� �������� * (�������� ���������)
#include <iostream>
#include <windows.h>
using namespace std;
class String
{
private:
	char *str = NULL; char* s = NULL;   // s = 0 ��� ����������� ��������� ������ ��� �������� ��������� � �����������
	int N1 = 80, N2, N3;
public:
	static int num_obj_str;
	String()                      // ����������� �� ���������
	{
		str = new char[N1 + 1];
		num_obj_str++;
	}
	String(int n)                 // �����������, ����������� ��������� ������ ������������� �������
	{
		str = new char[n + 1];
		num_obj_str++;
		N2 = n + 1;
	}
	String(const char *s)         // �����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������
	{
		N3 = strlen(s) + 1;
		str = new char[N3];
		strcpy(str, s);
		num_obj_str++;
	}
	String(const String& ob)      // ����������� �����
	{
	str = new char;
	*str = *ob.str;               // �������� �����
	int i = 0;
	while (ob.str[i] != '\0') {
	str[i] = ob.str[i];
	i++;
	}
	str[i] = '\0';
	num_obj_str++;
	}
	~String()                     // ����������
	{
		if (str != NULL) delete str;
		if (s != NULL) delete s;  // ���� ���������� ������ ��� �������� ��������� �� �������
		num_obj_str--;
	}
	void inter()                  // ����� ��� ����� ����� � ���������� �� ���������
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
	void inter(int n)             // ����� ��� ����� ������ ������������� ������� � ���������� 
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
		int n, n1 = strlen(s1.str)+1;                         // ������� ����� ������ 1 �������
		int n2 = strlen(s2.str) + 1;                          // ������� ����� ������ 2 �������
		if (n1 >= n2) 
			n = n1;
		else 
			n = n2;
		this->s = new char[n];                                // �������� ������ �� ���������� ������
		int i = 0, k = 0;
		while (s1.str[i] != '\0') {                           // ���� �� ������ 1 �������
			int j = 0;
			while (s2.str[j] != '\0') {                       // ���� �� ������ 2 �������
				if (s1.str[i] == s2.str[j]) {                 // ���� ������� ���������
					if (k != 0) {                             // ���� ����� �� ��� �������� � ������ ������
						int m = k;
						while (m != 0) {                      // ���� �� �����
							if (s[m - 1] != s1.str[i]) {      // � ������� ��� �� ��������
								m--;
							}
							else break;
						}
						if (m == 0) {                         // ���� �������� ��� �� ���������� ������
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
	void show()                   // ����� ��� ������ ������ �� �����
	{
		cout << str << endl;
	}
	static int show_Num_obj_str() // ����������� �������-����, ������� ����� ���������� ���������� ��������� �������� �����
	{
		return num_obj_str;
	}
};
int String::num_obj_str = 0;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char str1[100], str2[100], *str3;
	cout << "������� ������ ��� 1 �������: \n";
	std::cin.getline(str1, 101);
	String s1(str1);
	cout << "������� ������ ��� 2 �������: \n";
	std::cin.getline(str2, 101);
	String s2(str2);
	cout << "������ 1 �������: \n";
	s1.show();
	cout << "������ 2 �������: \n";
	s2.show();
	cout << "����� ������� ��� ���� �����: \n";
	str3 = s1*s2;
	cout << str3 << endl;
	system("pause");
	return 0;
}
