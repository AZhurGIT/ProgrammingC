// Visual Studio 2005
// 
#include <stdio.h>
//#include <windows.h>
#include <math.h>
#include <locale.h>


int main(int argc, char* argv[])
{
	int i, j;
	int a, b;
	float avg = 0;
	int* first = NULL;
	float* pAVG = NULL;
	a = b = 0;

	setlocale(LC_ALL, "Russian");

	printf("Введите размер таблицы (строки)\n");
	scanf_s("%d", &a);	
	printf("Введите размер таблицы (колонки)\n");
	scanf_s("%d", &b);

	pAVG = calloc(b, sizeof(float));	//Выделяем память для массива средних чисел
	first = calloc(a, sizeof(int));		//Выделяем память для массива с указателями на массивы строк
	for (i = 0; i< a; ++i)		//Перебираем массив указателей на строки
	{
		first[i] = calloc(b, sizeof(int));		//Выделяем память на строку
	}


	printf("Таблица %d x %d\n", a, b);	
	printf("Введите значения для таблицы построчно\n");
	for (i = 0; i < a; ++i)		//Перебираем строки
	{
		printf("Строка №%d\n", i + 1);
		avg = 0;
		for (j = 0; j < b; j++)		//Перебираем массивы в строке 
		{
			scanf_s("%d", ((int*)*(first + i) + j));	/*Вводим значение ячейки через указатель  *(first + i ) - смещение в массиве указателей на строки, содержит начальный адрес строки
														итоговое выражение содержит начальный адрес строки + смещение в строке */ 
			avg += *((int*)*(first + i) + j);	//Добавляем значение в массив для вычисления среднего
		}
		*(pAVG + i) = avg / b;		//Вычисляем среднее
	}

	printf("   Среднее");
	for (j = 1; j < b + 1; j++)		//Выводим номера колонок
	{
		printf("%9d ", j);
	}
	printf("\n");
	for (i = 0; i < a; ++i)		//Перебираем строки
	{
		printf("%10.2f", *(pAVG + i));		//Выводим среднее для строки
		for (j = 0; j < b; j++)		//Перебираем колонки в строке
			printf("%10d", *((int*)*(first + i) + j));		
		printf("\n");
	}



	free(*first);		//Здесь конечно ошибка память высвободиться только для одной строки
	free(first);
	first = NULL;

	printf("Для выхода нажмите enter");
	fflush(stdin);
	getchar();
	return 0;
}

