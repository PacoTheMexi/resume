#include <stdio.h>
#include <locale.h> //«десь объ€влена функци€ setlocale()
#include <stdlib.h> //«десь объ€влена функци€ system()

const int N = 10;
//объ€вление переменных
int K, L, i, tmp;
int arr[10];

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
		printf("¬ведите %d элемент массива:", i);
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
		printf("%d элемент массива:%d\n", i, arr[i]);
	}
	

	system("pause"); //пауза дл€ фиксации консоли
	return 0;
}