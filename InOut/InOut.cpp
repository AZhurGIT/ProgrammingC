// InOut.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <locale>
#include <iostream>

//#define IOSTREAM
#define ARRAYS


using namespace std;

int main()
{
	_tsetlocale(LC_ALL, L"Russian");

	int i = 0;
	char str[10] = {0};
	int result = 0;
#ifdef STDIO
	printf("---------- stdio ----------\n");
	printf("������� ����� �����: ");
	result = scanf("%d", &i);
	printf("������� %d ���������� %d\n", result,i);
	printf("������� ����� ������: ");
	result = scanf("%5c", str);
	printf("������� %d ����������: %s\n", result, str);
#endif
#ifdef IOSTREAM
	cout << "---------- iostream ----------" << endl;
	cout << "������� ����� �����: ";
	cin >> i;
	while (!cin.good())
	{
		cout << endl << "���� ��������, ���������" << endl;
		cin.clear();
		cin.ignore(INT32_MAX,'\n');
 		cin >> i;
	}
	cout << "�������: " << i << endl;
#endif	

#ifdef ARRAYS
	char str2[4] = { 'a','b','c' };
	printf("������ ��������: %s\n", str2);
	int a;
	a = static_cast<int>("Try to cast string to int");
	printf("Cast result: %d", a);

#endif

	_tsystem(L"pause");
    return 0;
}

