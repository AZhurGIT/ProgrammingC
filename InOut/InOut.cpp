// InOut.cpp: определяет точку входа для консольного приложения.
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
	printf("Попытка ввода числа: ");
	result = scanf("%d", &i);
	printf("Считано %d параметров %d\n", result,i);
	printf("Попытка ввода строки: ");
	result = scanf("%5c", str);
	printf("Считано %d параметров: %s\n", result, str);
#endif
#ifdef IOSTREAM
	cout << "---------- iostream ----------" << endl;
	cout << "Попытка ввода числа: ";
	cin >> i;
	while (!cin.good())
	{
		cout << endl << "Ввод неудачен, повторите" << endl;
		cin.clear();
		cin.ignore(INT32_MAX,'\n');
 		cin >> i;
	}
	cout << "Введено: " << i << endl;
#endif	

#ifdef ARRAYS
	char str2[4] = { 'a','b','c' };
	printf("Массив символов: %s\n", str2);
	int a;
	a = static_cast<int>("Try to cast string to int");
	printf("Cast result: %d", a);

#endif

	_tsystem(L"pause");
    return 0;
}

