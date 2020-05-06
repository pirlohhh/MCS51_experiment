// Ԥ����ָ�ͨ�� DEBUG ����� gdb ���Ի� keil ����
#define DEBUG 0
#if DEBUG
    #include "stdio.h"
    #define uchar int
#else
    #include "reg51.h"
    #define uchar unsigned char
#endif

uchar s[10]={0x10,0x35,0xa3,0xf7,0x2d,0x9d,0xe8,0x04,0x87,0xd0};    // 10���޷�����
uchar MAX = 0, MIN = 0, SUM = 0, BCDH = 0, BCDL = 0, AVG = 0;       // �洢���

void maxx(void)     // �ҵ����ֵ��keil ���в��������ͱ���ͬ�������Դ�Сд��
{
    uchar i = 0;
    MAX = s[0];
    for(i=1;i<10;i++)
    {
        if(s[i]>MAX)
            MAX = s[i];
    }
}

void minn(void)     // �ҵ���Сֵ
{
    uchar i = 0;
    MIN = s[0];
    for(i=1;i<10;i++)
    {
        if(s[i]<MIN)
            MIN = s[i];
    }
}

void mean(void)
{
    uchar i = 0;
    int sum = 0;
    for(i=0;i<10;i++)
        sum += s[i];
    AVG = (sum-MAX-MIN)/8;
}

void DEC_2_BCD(void)
{
    uchar tmp = 0;
    if (SUM>100)
        BCDH = SUM / 100;           // ��λ���� BCDH
    BCDL = SUM % 10;                // ��λ���� BCDL �ĵ�4λ 
    tmp = ((SUM -BCDL)/10) % 10;
    tmp = tmp<<4;
    BCDL += tmp;                    // ʮλ���� BCDL �ĸ�4λ 
    
}

void main()
{
    maxx();
    minn();
    SUM = MAX + MIN;
    mean();
    DEC_2_BCD();
}


