#include <stdio.h>
#include <locale.h> //����� ��������� ������� setlocale()
#include <stdlib.h> //����� ��������� ������� system()

//���������� ����������
int num = 1,i,k = 0;

//������� ���������
int main()
{
	setlocale(LC_ALL, "Russian"); //������������ ��������� ������ �� �������
	setlocale(LC_NUMERIC, "C"); //����������� ������� ����� - �����

	while (num != 0) {
		k = 0;
		printf("������� ����� �����:\n");
		scanf_s("%d", &num);

		for (i = 1; i < num; i++) if (num%i == 0) k++;
			
		if ((k == 1) || (num == 1))
			printf("TRUE\n");
		else
			printf("FALSE\n");
	}

	system("pause"); //����� ��� �������� �������
	return 0;
}