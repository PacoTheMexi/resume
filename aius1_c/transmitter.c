#include <stdlib.h>
#include <stdio.h>
#include "receiver.h"
#include "transmitter.h"

unsigned short CRC16(unsigned char *pcBlock, unsigned short len)
{
	unsigned short crc = 0xFFFF;
	unsigned char n;

	while (len--)
	{
		crc ^= *pcBlock++ << 8;

		for (n = 0; n < 8; n++)
		{
			crc = crc & 0x8000 ? (crc << 1) ^ 0x1021 : crc << 1;
		}
	}
	return crc;
}

dataPacket* createData(int packetNumber)
{
	dataPacket* newPacket = (dataPacket*)malloc(sizeof(dataPacket));
	if(newPacket != NULL)
	{
		newPacket->address = 12;
		newPacket->packetNumber = packetNumber+1;
		newPacket->instruction = 0x01;
		newPacket->ang_vel = (rand()&1 == 0) ? (10000+(rand()%1000)+(rand25()*10000)) : (10000-(rand()%1000)+(rand25()*20000));
		newPacket->torque = (rand()&1 == 0) ? (500+(rand()%100)+(rand25()*1000)) : (500-(rand()%100)+(rand25()*1000));
		newPacket->CRC16_value = CRC16((unsigned char*)newPacket,(unsigned short)(sizeof(dataPacket)-sizeof(unsigned short)));

		if(rand25())
		{
			newPacket->ang_vel += 2;
		}

		return newPacket;
	}
	else
	{
		printf("Memory allocation error\r\n");
		return NULL;
	}
}

int SendData(dataPacket* data, unsigned int size)
{
	printf("(Packet %2d) ", (data->packetNumber));
	if(!ReceiveData(data,size))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void show_packet(dataPacket* packet)
{
	printf("Address: %d\r\n",packet->address);
	printf("Packet Number: %d\r\n",packet->packetNumber);
	printf("Instruction: %d\r\n",packet->instruction);
	printf("Data: {Angular velocity = %5d | Torque = %5d}\r\n",packet->ang_vel,packet->torque);
	printf("CRC: %d\r\n\n",packet->CRC16_value);
}
