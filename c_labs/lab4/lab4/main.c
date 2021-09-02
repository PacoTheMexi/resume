#include <stdio.h>
#include <locale.h> //«десь объ€влена функци€ setlocale()
#include <stdlib.h> //«десь объ€влена функци€ system()

const int N = 10;
//объ€вление переменных
int K, L, i, temp;
int a[10];

//главна€ программа
int main()
{
	setlocale(LC_ALL, "Russian"); //переключение кодировки вывода на консоль
	setlocale(LC_NUMERIC, "C"); //разделитель дробной части - точка
	

	printf("¬ведите K:\n");
	scanf_s("%d", &K);
	printf("¬ведите L:\n");
	scanf_s("%d", &L);

	for (i = 0; i < N; i++) 
	{
		printf("¬ведите %d элемент массива\n", i);
		scanf_s("%d", &a[i]);
	}

	printf("ѕервоначальный массив: ");
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
	
	printf("ѕреобразованный массив:");
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	

	system("pause"); //пауза дл€ фиксации консоли
	return 0;
}