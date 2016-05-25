
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "i2c.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void print_usage(char* name){
	printf(
	"Usage:\n" \
    "	%s -d /dev/i2c-1									\n" \
    "		set i2c bus as /dev/i2c-1 [default:/dev/i2c-0]	\n" \
    "	%s -w [addr],[reg],[val]   							\n" \
    "		write a value [val] to register [reg]			\n" \
    "	%s -r [addr],[reg],[len]							\n" \
    "		read len bytes from [reg]						\n" \
    "	%s -s [addr]										\n" \
    "		search i2c valid regiser for device [addr]		\n" \
    "	%s -S												\n" \
    "		search i2c devices on bus						\n" \
	,name,name,name,name,name);
}

int set_bus(char* path)
{
	int ret=0;
	// check path exist
	
	// check path is char device
	
	// check path can be read/write 
	return ret;
}

int search_registers(U16 addr)
{
	int ret=0;
	// check add is valid address
	
	return ret;
}

void search_devices()
{
	// set devices on bus
}

int main (int argc, char **argv)
{
    int ret=0;
	int foptd=0,foptw=0,foptr=0, fopts=0,foptS=0;
	char* path=NULL;
	U16 waddr=0, wreg=0, wval=0;
	U16 raddr=0, rreg=0, rlen=0;
	U16 saddr=0;

    while((ret=getopt(argc, argv, "d:w:r:s:S"))!= -1)
    {
        switch(ret)
        {
            case 'd':
				foptd = 1;
                path = optarg;
                break;
            case 'w':
				if(3==sscanf(optarg,"%x,%x,%x",&waddr,&wreg,&wval)){
					foptw = 1;
				}
                break;
            case 'r':
				if(3==sscanf(optarg,"%x,%x,%x",&raddr,&rreg,&rlen)){
					foptr = 1;
				}
                break;
            case 's':
				fopts = 1;
				saddr = strtol(optarg,NULL,16);
                break;
            case 'S':
                foptS = 1;
                break;
        }
    }
	
	if(0==(foptd || foptw || foptr || fopts || foptS)){
		print_usage(argv[0]);
		ret = -1;
		goto RET;
	}
	
	if(foptd){
		if(access(path, F_OK)){
			printf("%s is not exist!\n",path);
			ret= -1;
			goto RET;
		}
		if(access(path, R_OK|W_OK|F_OK)){
			printf("%s can not be read/write!\n",path);
			ret= -1;
			goto RET;
		}
		i2c_bus_set(path);
	}
	
	if(foptw){
		int ret = i2c_write(waddr, wreg, (U8*)&wval, 1);
		if(!ret){
			printf("write: %02X[%02X]=%02X",waddr,wreg,wval);
		}
		else{
			printf("write failed!\n");
		}
	}
	
	if(foptr){
		U8 buf[256];
		int ret = i2c_read(raddr, rreg, buf, rlen);
		if(!ret){
			printf("read: %02X[%02X],%02X bytes",raddr,rreg,rlen);
			print_hex(buf,rlen);
		}
		else{
			printf("read failed!\n");
		}
	}
	
	if(fopts){
		U8 buff[256];
		int count = probe_regs(saddr,buff);
		printf("probe resutl: %d registers",count);
		if(count>0){
			print_hex(buff,count);
		}
		else{
			printf("\n");
		}
	}
	
	if(foptS){
		U8 buff[128];
		int count = probe_bus(buff);
		printf("probe resutl: %d devices",count);
		if(count>0){
			print_hex(buff,count);
		}
		else{
			printf("\n");
		}
	}
		
RET:	
   return ret;
}



