#include "head.h"

int vozvedenie_v_stepen(int a, int b)
{
    int i = 1;
    int rezult = 1;
    while (i++ <= b)
        rezult = rezult * a;
    return (rezult);
}
