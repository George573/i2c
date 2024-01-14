#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include "i2c.h"

int i2c_init(char slave_addr)
{
    int file;
    char filename [20];

    // Open i2c dev file 
    snprintf(filename, 19, "/dev/i2c-1");
    file = open(filename, O_RDWR);
    if (file < 0) {
        perror("Failed to open I2C bus");
        printf("%s\n", filename);
        return 1;
    }

    // Set slave address
    if (ioctl(file, I2C_SLAVE, slave_addr) < 0) {
        perror("Failed to set slave address");
        printf("%d\n", slave_addr);
        return 1;
    }

    return file;
}

void i2c_exit(int file)
{
    // Close i2c dev file
    close(file);
}

char i2c_read_byte(int file)
{
    char msg = i2c_smbus_read_byte(file);
    return msg;
}

short i2c_read_short(int file)
{
    short msg = 0;

    // Read first byte (msg = (buff)000000) 
    short buff = i2c_smbus_read_byte(file);
    msg = buff << 8;

    // Read second byte (msg = msg + buff)
    buff = i2c_smbus_read_byte(file);
    msg |= buff;

    return msg;
}

void i2c_write_byte(int file, char data)
{
    i2c_smbus_write_byte(file, data);
}

void i2c_write_short(int file, short data)
{
    // Write first buffer
    char buff = data >> 8;
    i2c_smbus_write_byte(file, buff);

    // Write second buffer
    buff = data;
    i2c_smbus_write_byte(file, buff);
}