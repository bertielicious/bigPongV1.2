#include "config.h"
#include <stdbool.h>
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"

void splashScreen(void)
{
    uchar row;
    uchar splish[8] = {0x7c,0x90,0x90,0x60,0x0c,0x12,0x12,0x0c};
    uchar splishL[8] = {0x70,0x80,0x80,0x70,0x00,0x0e,0x15,0x17};
    for (row = 1; row<9; row++)
    {
    CS = LO;
    sendNoSPIbyte();
    
    sendSPIbyte(row, splish[row-1]);
    CS = HI;
    
    CS = LO;
    sendSPIbyte(row, splishL[row-1]);
   
    sendNoSPIbyte();
    CS = HI;
    }
}
   
