
#ifndef __I2C_H__
#define __I2C_H__

#define PLEN 32

typedef unsigned char U8;
typedef unsigned int U16;

extern void i2c_bus_set(const char* ibus);
extern int i2c_read(const U8 addr, const U8 reg, U8* buff, const U8 len);
extern int i2c_write(const U8 addr, const U8 reg, const U8* buff, const U8 len);
extern int probe_bus(U8* pbuff);
extern int probe_regs(const U8 addr, U8* pbuff);
extern void print_hex(const U8* pbuff, const U16 len);
#endif
