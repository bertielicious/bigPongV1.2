#include "config.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
uchar colPattern(bool matrix, uchar col, uchar row, bool bit)
{
    uchar  resultByte;
    if(col==7)
    resultByte = 0;

    resultByte =  resultByte + (bit * (1<<(col)));
    if(matrix==1)
    {
        CS = LO;
        sendSPIbyte(row, resultByte);    
        sendNoSPIbyte();           // write to right LED matrix  
        CS = HI; 
    }
    else
    {
        CS = LO;
        sendNoSPIbyte();           // write to left LED matrix  
        sendSPIbyte(row, resultByte);    
        CS = HI;
    }
   // printf("%d    %d   %d\n", col, bit, resultByte);
    return resultByte;
}
