#include "reg51.h"
#include "interrupt_func.h"
#define uchar unsigned char
void update(void);

uchar ctrl_led  = 0xFE;

void press_twice() interrupt 3      // �������������κ󣬼����� TIM_1 �����ж�
{
    TIM_0_continue();               // �򿪶�ʱ�� TIM_0
}


uchar i = 0;
void shine_led() interrupt 1        // ����ʱ�� TIM_0 �����жϣ���50ms ʱ�䵽
{
    TIM_0_continue();               // ��ʱ�� TIM_0 �ֶ���װ
    i++;
    if(i==20)                       // i=20ʱ���� 1s ��ʱʱ�䵽
    {
        i = 0;                      // ��ձ�־λ
        update();                   // ���� LED �Ƽ������߼�
    }
}

void update(void)
{
    P1 = ctrl_led;                  // ���� LED
    if (ctrl_led == 0xFF)           // ��һ��ѭ��������
    {
        ctrl_led = 0xFE;            // �ָ���ֵ
        TIM_0_pause();              // �رն�ʱ�� TIM_0
        TIM_1_rrestart();           // ��װ������
    }  
    else
    {
        ctrl_led = ctrl_led << 1;
        ctrl_led = ctrl_led | 0x01; // �����¸�ʱ�� LED �Ŀ����ź�
    } 
}