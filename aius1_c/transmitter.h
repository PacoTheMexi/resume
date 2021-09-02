#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_


#pragma pack(push,1)
typedef struct
{
	short address;
	short packetNumber;
	unsigned short ang_vel;
	unsigned short torque;
	unsigned char instruction;
	unsigned short CRC16_value;
}dataPacket;
#pragma pack(pop)

dataPacket* createData(int packetNumber);//������� � ��������� ����� � ������� packetNumber
int SendData(dataPacket* data, unsigned int size); //SendData
void show_packet(dataPacket* packet); //����������� ����������� ������ ������
unsigned short CRC16(unsigned char *pcBlock, unsigned short len); // ������ ��
int rand25(); //������� ����������� 75%

#endif //TRANSMITTER_H_
