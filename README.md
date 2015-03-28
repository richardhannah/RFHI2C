# RFHI2C
Quick and easy I2C library and C# Wrapper class.

Includes C library class for interfacing with Linux I2C adapter, and C# Wrapper class. Specifically
written for Raspbian (Raspberry Pi linux variant), but should work fine with other linux variants.


Usage:

Compile the C source code file (libRFHI2C.c) with following command

cc -c libRFHI2C.c

Then create the shared object library with

cc -shared libRFHI2C.o -o libRFHI2C.so

Once the shared library is created then place it in the bin folder of
the C# project (bin/Debug usually). This should allow you to use the
C library via the C# Wrapper.
