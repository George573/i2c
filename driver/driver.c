#include "driver.h"
#include "i2c.h"

static int file;

static short regs_masks[8] = {
    CONV_RESULT_MASK,
    ALERT_STATUS_MAKS,
    CONFIG_MASK,
    LOW_LIMIT_MASK,
    HIGH_LIMIT_MASK,
    HYSTERESIS_MASK,
    LOW_CONV_MASK,
    HIGH_CONV_MASK
};

void dr_init(short slave_addr)
{
    file = i2c_init(slave_addr);
}

void dr_exit()
{
    i2c_exit(file);
}

short dr_get_reg_data(short reg)
{
    if (reg >= 0 && reg <= 7) {
        i2c_write_short(file, reg);
        short msg = i2c_read_short(file);
        return msg;
    }
    return -1;
}

int dr_set_reg_data(short reg, short data)
{
    if (reg >= 0 && reg <= 7) {
        if (regs_masks[reg] & data) {
            i2c_write_short(file, reg);
            i2c_write_short(file, data);
            return 0;
        }
    }
    return -1;
}