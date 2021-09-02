#include <stdio.h>
#include <locale.h> //«десь объ€влена функци€ setlocale()
#include <stdlib.h> //«десь объ€влена функци€ system()

//объ€вление переменных
int num = 1,i,k = 0;

//главна€ программа
int main()
{
	setlocale(LC_ALL, "Russian"); //переключение кодировки вывода на консоль
	setlocale(LC_NUMERIC, "C"); //разделитель дробной части - точка

	while (num != 0) {
		k = 0;
		printf("¬ведите целое число:\n");
		scanf_s("%d", &num);

		for (i = 1; i < num; i++) if (num%i == 0) k++;
			
		if ((k == 1) || (num == 1))
			printf("TRUE\n");
		else
			printf("FALSE\n");
	}

	system("pause"); //пауза дл€ фиксации консоли
	return 0;
}