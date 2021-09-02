#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "transmitter.h"
#include "receiver.h"

#define PACKS 100

int main(int argc, char *argv[])
{
	setlocale(LC_ALL,"Rus");
	printf("��������� ���������� 100 ������� �� ���������� �������\r\n"
			"��� �������� ������ ������ ������ � ������������ 25%% ������ ������ ��� �������� ��������� (��������� ������ ������)\r\n\r\n"
			"��� ������������� ����� '-show' ��������� ����� ���������� ���������� ������� ������ ����� ���������\r\n"
			);


	srand(time(0));

	dataPacket* packets[PACKS];

	int i;
	int show = 0;

	if((argc == 2) && (strcmp(argv[1],"-show") == 0))
	{
		show = 1;
	}
	else if(argc > 2)
	{
		puts("Unknown input");
		return 1;
	}

	for (i = 0; i < PACKS; i++)
	{
		packets[i] = (dataPacket*)malloc(sizeof(dataPacket));
		if(packets[i])
		{
			packets[i] = createData(i);
		}
		else
		{
			printf("Memory allocation error");
			return 1;
		}
	}

	if(show == 0)
	{
		for (i = 0; i < PACKS; i++)
		{
			SendData(packets[i],sizeof(dataPacket));
		}
	}
	else
	{
		for (i = 0; i < PACKS; i++)
		{
			SendData(packets[i],sizeof(dataPacket));
			show_packet(packets[i]);
		}
	}

	for(i = 0; i < PACKS; i++)
	{
		free(packets[i]);
	}

	puts("Press Enter to exit the program");
	getchar();
	return 0;
}

