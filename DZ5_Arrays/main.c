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

	printf("������� ������ ������� (������)\n");
	scanf_s("%d", &a);	
	printf("������� ������ ������� (�������)\n");
	scanf_s("%d", &b);

	pAVG = calloc(b, sizeof(float));	//�������� ������ ��� ������� ������� �����
	first = calloc(a, sizeof(int));		//�������� ������ ��� ������� � ����������� �� ������� �����
	for (i = 0; i< a; ++i)		//���������� ������ ���������� �� ������
	{
		first[i] = calloc(b, sizeof(int));		//�������� ������ �� ������
	}


	printf("������� %d x %d\n", a, b);	
	printf("������� �������� ��� ������� ���������\n");
	for (i = 0; i < a; ++i)		//���������� ������
	{
		printf("������ �%d\n", i + 1);
		avg = 0;
		for (j = 0; j < b; j++)		//���������� ������� � ������ 
		{
			scanf_s("%d", ((int*)*(first + i) + j));	/*������ �������� ������ ����� ���������  *(first + i ) - �������� � ������� ���������� �� ������, �������� ��������� ����� ������
														�������� ��������� �������� ��������� ����� ������ + �������� � ������ */ 
			avg += *((int*)*(first + i) + j);	//��������� �������� � ������ ��� ���������� ��������
		}
		*(pAVG + i) = avg / b;		//��������� �������
	}

	printf("   �������");
	for (j = 1; j < b + 1; j++)		//������� ������ �������
	{
		printf("%9d ", j);
	}
	printf("\n");
	for (i = 0; i < a; ++i)		//���������� ������
	{
		printf("%10.2f", *(pAVG + i));		//������� ������� ��� ������
		for (j = 0; j < b; j++)		//���������� ������� � ������
			printf("%10d", *((int*)*(first + i) + j));		
		printf("\n");
	}



	free(*first);		//����� ������� ������ ������ ������������� ������ ��� ����� ������
	free(first);
	first = NULL;

	printf("��� ������ ������� enter");
	fflush(stdin);
	getchar();
	return 0;
}

