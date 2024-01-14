/*
 * my_spi_useful.h
 *
 *  Created on: Nov 14, 2023
 *      Author: George
 */

#ifndef INC_USEFUL_H_
#define INC_USEFUL_H_

/*------------DEFINES-------------*/
#define MY_SPI_WRITE_MOD	1
#define MY_SPI_READ_MOD		0
/*--------------------------------*/

/*------------ERRORS-------------*/
#define WRONG_ADRESS	~0u
#define WRONG_VAL		~1u
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

/*-----REGISTERS DEFAULT VAL------*/
#define CONV_RESULT_DEF_VAL	0x0
#define ALERT_STATUS_DEF_VAL	0x3
#define CONFIG_DEF_VAL			0xFD
#define LOW_LIMIT_DEF_VAL		0xFFF
#define HIGH_LIMIT_DEF_VAL		0xFFF
#define HYSTERESIS_DEF_VAL		0xFFF
#define LOW_CONV_DEF_VAL		0xFFF
#define HIGH_CONV_DEF_VAL		0xFFF
/*--------------------------------*/

#endif /* INC_USEFUL_H_ */
