#include "config.h"
#include "config.h"
#include "configPorts.h"
#include "configOsc.h"
#include "configSPI.h"
#include "init1_max7219.h"
#include "init2Max7219.h"
#include "configUsart.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
#include "NumToColVal.h"
#include "clearScreen.h"
#include "splashScreen.h"
#include "colPattern.h"
#include "stdio.h"
void main (void)
{
    configPorts();
    configOsc();
    configSPI();
    init1_max7219();
    init2Max7219();
    configUsart();
    printf("Hello Phil\n");
  
    splashScreen();
    __delay_ms(2000);
    clearScreen();
    
    bool matrix = 1;// right matrix
     uchar row, col, result = 0;
     row = 8;    
       /*  col = 255;  
         row = 8;
         
         CS = LO;
         sendSPIbyte(row, col);    
         sendNoSPIbyte();           // write to right LED matrix  
         CS = HI; */
     
       bool binaryByte[8] = {1,1,1,1,1,1,1,1};
        for(col = 7; col >=0; col--) 
        {
          //result = colPattern(matrix, col,row, binaryByte[col]);// pass array by value
            result = colPattern(matrix, col, row, &binaryByte[col]);// pass array by address
          if(col==0)
              break;
        }
       
       
       
       matrix = 0;//left matrix
       row = 1;
       bool binaryByte1[8] = {0,0,0,1,1,1,0,0};
        for(col = 7; col >=0; col--) 
        {
          //result = colPattern(matrix, col, row, binaryByte1[col]);// pass array by value
            result = colPattern(matrix, col, row, &binaryByte1[col]);// pass array by address
          if(col==0)
              break;
        }
       
       
     
    while(1)
    {
        
    }
}
