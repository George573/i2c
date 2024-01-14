#ifndef DRIVER
#define DRIVER

void dr_init(short slave_addr);
short dr_get_reg_data(char reg);
int dr_set_reg_data(char reg, short data);


/*--------REGISTERS MASK----------*/
#define CONV_RESULT_MASK	0x0
#define ALERT_STATUS_MAKS	0x3
#define CONFIG_MASK			0xFD
#define LOW_LIMIT_MASK		0xFFF
#define HIGH_LIMIT_MASK		0xFFF
#define HYSTERESIS_MASK		0xFFF
#define LOW_CONV_MASK		0xFFF
#define HIGH_CONV_MASK		0xFFF
/*--------------------------------*/

/*---------REGISTERS ADR----------*/
enum regs {
    CONV_RESULT,
    ALERT_STATUS,
    CONFIG,
    LOW_LIMIT,
    HIGH_LIMIT,
    HYSTERESIS,
    LOW_CONV,
    HIGH_CONV
};
/*--------------------------------*/

#endif