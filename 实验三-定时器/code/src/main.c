#include "REG51.H"
#include "interrupt_func.h"

void init()     // ��ʼ����ʱ���ͼ�����
{
    TIM_0_init();
    TIM_1_init();
}


void main()
{
    init();
    P1 = 0xFF;  // �ϵ�LEDȫ��Ϩ��
    while(1);
}

