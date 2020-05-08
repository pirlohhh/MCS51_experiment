#include "8051.H"
#define uchar unsigned char

uchar i = 0;
sbit LED = P1^0;

void continuee() interrupt(EXT0_VECTOR)
{
    i++;
    if(i == 3)
    {
        i = 0;
        LED = ~LED;
    }
}