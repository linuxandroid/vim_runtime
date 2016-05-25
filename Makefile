
CFLAGS= -Wall -O2 -static
CC=arm-none-linux-gnueabi-gcc

iu: pre
	$(CC) $(CFLAGS) iu.o i2c_msg.o -o $@


pre: i2c_msg.o iu.o

all: iu
	
clean: 
	rm -f i2c_msg.o i2c_file.o iu.o iu

