#include <stdio.h>
#include "driver.h"

#define SLAVE_ADDRESS 0x60

int main()
{
    dr_init(SLAVE_ADDRESS);
    short data = dr_get_reg_data(1);
    printf("Here is data from 0x1: %d\n", data);
    return 0;
}