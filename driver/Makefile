CC=gcc
CFLAGS=-I.

DEPS = i2c.h driver.h
OBJ = driver.o i2c.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

i2c_driver: $(OBJ)
	$(CC) -o $@ $^ -li2c