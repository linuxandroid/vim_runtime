
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include "i2c.h"

// set default i2c bus.
static char i2c_bus[PLEN] = "/dev/i2c-0";

// open i2c bus
static int i2c_bus_open()
{
    int fd = open(i2c_bus, O_RDWR);
	if (fd < 0){
        printf("open i2c bus %s failed\n",i2c_bus);
	}
	return fd;
}

// close i2c bus
static void i2c_bus_close(int fd)
{
	if (fd < 0)
		return;
	close(fd);
}

// set i2c bus
void i2c_bus_set(const char* ibus)
{
	int i=0;
	for(i=0; i<PLEN; i++){
		if(ibus[i])
			i2c_bus[i]=ibus[i];
		else
			i2c_bus[i]=0;
	}
}

// read chip addr from reg into buff with len bytes
int i2c_read(const U8 addr, const U8 reg, U8* buff, const U8 len)
{
    int fd,ret;
    U8 outbuff;
    struct i2c_rdwr_ioctl_data ioctl_data;
    struct i2c_msg msgs[2];
	
    fd = i2c_bus_open();
    if(fd<0){
        return -1;
    }
    
    outbuff=reg;
    
    msgs[0].addr= addr>>1;
    msgs[0].len= 1;
    msgs[0].flags= 0;
    msgs[0].buf= &outbuff;
    
    msgs[1].addr= addr>>1;
    msgs[1].len= len;
    msgs[1].flags = I2C_M_RD;
    msgs[1].buf= buff;
    
    ioctl_data.nmsgs= 2;
    ioctl_data.msgs= msgs;
    ret = ioctl(fd, I2C_RDWR, &ioctl_data);

    i2c_bus_close(fd);
	
	return !(ret==2);  
}

// write chip addr into reg from buff with len bytes
int i2c_write(const U8 addr, const U8 reg, const U8* buff, const U8 len)
{
    int fd,ret;
    U8* puchar;
    struct i2c_msg  msgs;
    struct i2c_rdwr_ioctl_data ioctl_data;
    
    fd = i2c_bus_open();
	if(fd<0) return -1;

    puchar = (U8*)malloc(len+1);
    if(!puchar){
        printf("malloc failed\n");
        i2c_bus_close(fd);
        return -1;
    }
    
    puchar[0] = reg;
    memcpy(puchar+1,buff,len);
    
    msgs.addr= addr>>1;
    msgs.len= len+1;
    msgs.flags= 0;
    msgs.buf= puchar;
    
    ioctl_data.nmsgs= 1;
    ioctl_data.msgs= &msgs;
    ret = ioctl(fd, I2C_RDWR, &ioctl_data);
    
    free(puchar);
    i2c_bus_close(fd);
    
	return !(ret==1);
}

// search devices on bus.
int probe_bus(U8* pbuff)
{
    int i,count=0;
	U8 value;
   
	for(i=2; i<0xFF;i=i+2){
		if(!i2c_read(i,0,&value,1)){
			pbuff[count++] = i;
		}
		usleep(100);
	}
	return count;
}

// probe registers on device
int probe_regs(const U8 addr, U8* pbuff)
{
    int i,count=0;
	U8 value;

	for(i=0; i<0x100;i++){
		if(!i2c_read(addr,i,&value,1)){
			pbuff[count++] = i;
		}
		usleep(100);
	}	
	return count;  
}

// print buffer in hex
void print_hex(const U8* pbuff, const U16 len)
{
	int i=0;
	for(i=0; i<len; i++){
		if(0==i%16){
			printf("\n%04X:",i);
		}
		if(0==i%8){
			printf(" %02X ",pbuff[i]);
		}
		else{
			printf("%02X ",pbuff[i]);
		}
	}
	printf("\n");
}
