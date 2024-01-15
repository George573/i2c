#include <stdio.h>
#include "driver.h"

#define SLAVE_ADDRESS 0x60

int main()
{
    dr_init(SLAVE_ADDRESS);
    short data = dr_get_reg_data(2);
    printf("Here is data from 0x2: %d\n", data);
    data = CONFIG_MASK & (~(0ul));
    dr_set_reg_data(2, data);
    data = dr_get_reg_data(2);
    printf("Here is data from 0x2: %d\n", data);
    dr_exit();
    return 0;
}