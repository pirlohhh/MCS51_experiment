#include "reg51.h"
#include "8155_func.h"
#include "intrins.h"
#define uchar unsigned char

uchar num_encode[] = /* �����������ǰ�з�������ʹ�ù���������*/
    {0x8c,0x89};

uchar LED_num[] =   /* ѡ���ĸ� LED ��������������� 0 ����ʾ��Ϩ��*/
    {255,223,239,247,251,253,254};

void delay1s(void)   //��� 0us
{
    unsigned char a,b,c;
    for(c=167;c>0;c--)
        for(b=171;b>0;b--)
            for(a=16;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}

void main()
{
    C8155_init(0x0f);

    while(1)
    {
        C8155_PC = LED_num[1];
        C8155_PB = num_encode[0];
        delay1s();

        C8155_PC = LED_num[1];
        C8155_PB = num_encode[1];
        delay1s();
    }
    
}