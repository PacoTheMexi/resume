#include <stdio.h>
#include <locale.h> //����� ��������� ������� setlocale()
#include <stdlib.h> //����� ��������� ������� system()

const int N = 10;
//���������� ����������
int K, L, i, temp;
int a[10];

//������� ���������
int main()
{
	setlocale(LC_ALL, "Russian"); //������������ ��������� ������ �� �������
	setlocale(LC_NUMERIC, "C"); //����������� ������� ����� - �����
	

	printf("������� K:\n");
	scanf_s("%d", &K);
	printf("������� L:\n");
	scanf_s("%d", &L);

	for (i = 0; i < N; i++) 
	{
		printf("������� %d ������� �������\n", i);
		scanf_s("%d", &a[i]);
	}

	printf("�������������� ������: ");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	for (i = 0; i <= ((L - K) / 2); i++)
	{
		temp = a[K + i];
		a[K + i] = a[L - i];
		a[L - i] = temp;
	}
	
	printf("��������������� ������:");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	

	system("pause"); //����� ��� �������� �������
	return 0;
}