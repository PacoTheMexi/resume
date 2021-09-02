#include <stdio.h>
#include <locale.h> //����� ��������� ������� setlocale()
#include <stdlib.h> //����� ��������� ������� system()

const int N = 10;
//���������� ����������
int K, L, i, tmp;
int arr[10];

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
		printf("������� %d ������� �������:", i);
		scanf_s("%d", &arr[i]);
	}

	for (i = K;((i>=K) && (i<=L)); i++)
	{
		tmp = arr[i];
		arr[i] = arr[9 - i];
		arr[9 - i] = tmp;
	}

	for (i = 0; i < N; i++)
	{
		printf("%d ������� �������:%d\n", i, arr[i]);
	}
	

	system("pause"); //����� ��� �������� �������
	return 0;
}