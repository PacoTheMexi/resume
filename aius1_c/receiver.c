#include <stdio.h>
#include <stdlib.h>
#include "transmitter.h"
#include "receiver.h"

int ReceiveData(dataPacket* packet, unsigned int size)
{
	unsigned short CRC_check = CRC16((unsigned char*)packet,(unsigned short)(sizeof(dataPacket)-sizeof(unsigned short)));

	if((CRC_check) != (packet->CRC16_value))
	{
		printf("CRC doesn't match\r\n");
		return 1;
	}
	else
	{
		if((packet->ang_vel) < 20 || (packet->ang_vel>20000))
		{
			printf("Warning: Critical angular velocity\r\n");
		}
		else if((packet->torque < 400) ||(packet->torque > 600))
		{
			printf("Warning: Critical torque\r\n");
		}
		else
		{
			printf("All systems nominal\r\n");
		}
		return 0;
	}

}

int rand25()
{
	return (rand()&1)&(rand()&1);
}

