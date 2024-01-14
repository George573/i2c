///*
// * spi_slave.h
// *
// *  Created on: Nov 13, 2023
// *      Author: George
// */
//
#ifndef INC_I2C_SLAVE_H_
#define INC_I2C_SLAVE_H_

#include <machine/_default_types.h>

/*---------FUNC PROTOTYPE---------*/
uint16_t Slave_Listen4(I2C_HandleTypeDef *hspi);
uint16_t slave_set_reg_data(I2C_HandleTypeDef *hspi, uint8_t address);
uint16_t slave_send_reg_data(I2C_HandleTypeDef *hspi, uint8_t address);
/*--------------------------------*/

#endif /* INC_I2C_SLAVE_H_ */
