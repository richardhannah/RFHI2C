/*
    File:       RFHI2C.cs   
    Version:    1.0
    Date:       20/03/2015 
    Author: Richard Ferguson-Hannah

    Namespace: RFHI2CWrapper
    Exposes: Init(),ReadRegister(),WriteRegister()
    Description:
    Wrapper class for interfacing with C I2C shared library 
*/




using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace RFHI2CWrapper
{
    public class RFHI2C
    {
        [DllImport("libRFHI2C.so", EntryPoint = "Init")]
        public static extern int Init(int adapter, int devId);

        [DllImport("libRFHI2C.so", EntryPoint = "ReadRegister")]
        public static extern int ReadRegister(int handle, int registerId);


        [DllImport("libRFHI2C.so", EntryPoint = "WriteRegister")]
        public static extern void WriteRegister(int handle, int registerId, int data);


    }
}
