#include "config.h"
uchar NumToColVal(uchar num)
{

    unsigned char column;
    switch(num)
    {
        case 1:
            column = 1<<(num-1);
            break;
        case 2:
            column = 1<<(num-1);
            break;
        case 3:
            column = 1<<(num-1);
            break;
        case 4:
            column = 1<<(num-1);
            break;
        case 5:
            column = 1<<(num-1);
            break;
        case 6:
            column = 1<<(num-1);
            break;
        case 7:
            column = 1<<(num-1);
            break;
        case 8:
            column = 1<<(num-1);
            break;
        default:
            column = 0;
            break;
    }
    return column;
}
