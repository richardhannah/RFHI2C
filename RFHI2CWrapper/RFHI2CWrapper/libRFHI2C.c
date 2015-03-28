/*
File:       libRFHI2C.c
Version:    1.0
Date:       20/03/2015
Author: Richard Ferguson-Hannah

Namespace: RFHI2CWrapper
Exposes: Init(),ReadRegister(),WriteRegister()
Description:
C library class for interfacing with Linux I2C adapter. Specifically
written for Raspbian (Raspberry Pi linux variant). Intended for use with
C# RFHI2CWrapper library.

Usage:

Compile source code with following command

cc -c libRFHI2C.c

Then create the shared object library with

cc -shared libRFHI2C.o -o libRFHI2C.so

Once the shared library is created then place it in the bin folder of
the C# project (bin/Debug usually). This should allow you to use the
C library via the C# Wrapper.

*/




#include <stdio.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <stdlib.h>


int Init(int _adapter, int _devId){
	int file;
	  int adapter_nr = _adapter; /* probably dynamically determined */
	  char filename[20];
	  
	  snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
	  file = open(filename, O_RDWR);
	  if (file < 0) {
		printf("unable to open I2C adapter");
		exit(1);
	  }
	  
	  int addr = _devId; /* The I2C address */

	  if (ioctl(file, I2C_SLAVE, addr) < 0) {
		printf("unable to connect to device");
		exit(1);
	  }
	  
	  return file;
	
}

int ReadRegister(int _handle, int _reg){
	
	__u8 reg = _reg; /* Device register to access */
	  __s32 res;
	  char buf[10];

	  /* Using SMBus commands */
	  res = i2c_smbus_read_byte_data(_handle, reg);
	  if (res < 0) {
		 printf("unable to read register");
	  } else {
		 //printf ("%d",res);
	  }
	
	return res;
	
}

int WriteRegister(int _handle, int _reg, int _data){
	
	i2c_smbus_write_byte_data(_handle, _reg, _data);
	
	/* Using I2C Write, equivalent of 
     i2c_smbus_write_word_data(file, reg, 0x6543) */
  //buf[0] = reg;
  //buf[1] = 0x43;
  //buf[2] = 0x65;
  //if (write(file, buf, 3) != 3) {
    /* ERROR HANDLING: i2c transaction failed */
  //}
	
	
}



