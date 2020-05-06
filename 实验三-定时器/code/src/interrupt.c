#include "REG51.H"


void TIM_0_init(void)
{
    // 50ms �ж�һ��
    TMOD = TMOD | 0x01;     // ��ʱ��0ѡ��ʽ1����
    TH0 = 0x3C;
    TL0 = 0xB0;             // װ���ֵ��50ms�ж�һ��
    ET0 = 1;                // �� T0 �ж�
    EA = 1;                 // �����ж�
    PT0 = 1;                // ���ø����ȼ�
    TR0 = 0;                // T0 ����ʼ����������
}

void TIM_0_continue(void)
{
    TH0 = 0x3C;
    TL0 = 0xB0;             // ����װ���ֵ��50ms�ж�һ��
    TR0 = 1;                // T0 ����
}

void TIM_0_pause(void)
{
    TR0 = 0;                // T0 �ر�
}

void TIM_1_init(void)
{
    // ���������ۼ�������������ж�
    TMOD = TMOD | 0x60;     // ������1ѡ��ʽ2����
    TH1 = 0xFE;
    TL1 = 0xFE;
    ET1 = 1;                // �� T1 �ж�
    EA = 1;                 // �����ж�
    PT1 = 0;                // ���õ����ȼ�
    TR1 = 1;                // T1 ����
}


void TIM_1_rrestart(void)
{
    TL1 = 0xFE;             // T1 ��װ
}