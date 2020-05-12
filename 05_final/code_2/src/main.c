#include "8051.h"
#include "LED_func.h"
#include "ADC_func.h"
#include "interrupt_func.h"




void main()
{
    static uchar num = 0;
    EX1_init();
    while(1)
    {
        
        ADC_choose_INO();   // ѡ��ADC��INO ��Ϊģ��������
                            // ʹ��Y7���ƣ���ַ E000H
        while (IE1 != 1);   // ��δ�����жϣ���δת������ǳ���ȴ�
        num = ADC_INO;      // ����ת����������
        LED_show(1,num/100);
        LED_show(2,(num%100)/10);
        LED_show(3,num%10);
    }
}