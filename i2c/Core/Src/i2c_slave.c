#include "stm32f7xx_hal.h"
#include "useful.h"
#include "i2c_slave.h"

/*-----------registers------------*/
// Registers (set to default values on creation)
uint16_t regs[8] = {
		CONV_RESULT_DEF_VAL,
		ALERT_STATUS_DEF_VAL,
		CONFIG_DEF_VAL,
		LOW_LIMIT_DEF_VAL,
		HIGH_LIMIT_DEF_VAL,
		HYSTERESIS_DEF_VAL,
		LOW_CONV_DEF_VAL,
		HIGH_CONV_DEF_VAL
};

// Registers' masks
uint16_t masks[8] = {
		CONV_RESULT_MASK,
		ALERT_STATUS_MAKS,
		CONFIG_MASK,
		LOW_LIMIT_MASK,
		HIGH_LIMIT_MASK,
		HYSTERESIS_MASK,
		LOW_CONV_MASK,
		HIGH_CONV_MASK
};
/*-------------------------------------*/

uint16_t Slave_i2c_Resieve_16(I2C_HandleTypeDef *hspi)
{
	uint16_t msg = 0;

	// Read first byte (msg = (buff)000000)
	uint16_t buff;
	HAL_I2C_Slave_Receive(hspi, &buff, 1, 1000);
	msg = buff << 8;

	// Read second byte (msg = msg + buff)
	HAL_I2C_Slave_Receive(hspi, &buff, 1, 1000);
	msg |= buff;

	return msg;
}

uint16_t Slave_i2c_Transmit_16(I2C_HandleTypeDef *hspi, uint16_t data)
{
	// Write first buffer
	uint8_t buff = data >> 8;
	HAL_I2C_Slave_Transmit(hspi, &buff, 1, 1000);

	// Write second buffer
	buff = data;
	HAL_I2C_Slave_Transmit(hspi, &buff, 1, 1000);
}

uint16_t Slave_Listen4(I2C_HandleTypeDef *hspi)
{
	uint8_t address;
	HAL_I2C_Slave_Receive(hspi, &address, 1, HAL_MAX_DELAY);

	if (address & 1) {
		slave_set_reg_data(hspi, address >> 1);
	} else {
		slave_send_reg_data(hspi, address >> 1);
	}
}

uint16_t slave_set_reg_data(I2C_HandleTypeDef *hspi, uint8_t address)
{
	uint16_t data = Slave_i2c_Resieve_16(hspi);
	if (address >= 0 && address <= 7) {
		regs[address] = data & masks[address];
	}

}
uint16_t slave_send_reg_data(I2C_HandleTypeDef *hspi, uint8_t address)
{
	if (address >= 0 && address <= 7)
		Slave_i2c_Transmit_16(hspi, regs[address]);
	else
		Slave_i2c_Transmit_16(hspi, 0);
}
