#ifndef I2C
#define I2C

int i2c_init(char slave_addr);
void i2c_exit(int file);
char i2c_read_byte(int file);
short i2c_read_short(int file);
void i2c_write_byte(int file, char data);
void i2c_write_short(int file, short data);

#endif