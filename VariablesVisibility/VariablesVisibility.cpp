// VariablesVisibility.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
extern int globalInt;
extern int staticGlobalInt;

int main()
{
	const int constInt = 55;
	int localInt = 10;
	int* heapInt = new int(33);
	int* localIntAddress = &localInt;
	int* globalIntAddress = &globalInt;
	short int SSreg;
	short int CSreg;
	short int DSreg;
	const int* constIntAddress = &constInt;
	printf("Global integer: %d\n", globalInt);
	printf("Static global integer: %d\n", staticGlobalInt);
	_asm
	{
		mov AX, SS;
		mov SSreg, AX;
		mov AX, CS;
		mov CSreg, AX;
		mov AX, DS;
		mov DSreg, AX;
	}

	_tsystem(L"pause");
    return 0;
}
