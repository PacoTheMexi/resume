#include <stdio.h>
#include <locale.h> //����� ��������� ������� setlocale()
#include <stdlib.h> //����� ��������� ������� system()


//���������� ����������
int i, j, j_max, max;
int a1[4][7], a2[4][8]; 

//������� ���������
int main()
{
	setlocale(LC_ALL, "Russian"); //������������ ��������� ������ �� �������
	setlocale(LC_NUMERIC, "C"); //����������� ������� ����� - �����

	for (i = 0; i < 4; i++)
		for (j = 0; j < 7; j++)
			a1[i][j] = j;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 7; j++)
		{
			printf("%2d ", a1[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	max = a1[0][0];
	j_max = 0;

	for (i = 0; i < 4; i++)
		for (j = 0; j < 7; j++)
			if (a1[i][j] > max)
			{
				max = a1[i][j];
				j_max = j;
			}

	for (i = 0; i < 4; i++)
		for (j = 0; j < 7;j++)
			a2[i][j] = a1[i][j];

	for (i = 0,j=7;i<4;i++)
	{
		a2[i][j] = a1[i][j_max];
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%2d ", a2[i][j]);
		}
		printf("\n");
	}


	system("pause"); //����� ��� �������� �������
	return 0;
}