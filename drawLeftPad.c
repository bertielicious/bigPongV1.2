#include "config.h"
void drawLeftpad(bool *arr, uchar start, uchar finish)
{
    uchar row, col = 0;
    col = 1;
    for(row = start; row < finish; row++)
    {
        pongArr[row][col] = 1;
    }
}
