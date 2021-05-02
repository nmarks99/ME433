# (I2C) Inter-integrated circuit
- style of bus communication 
- synchronous (controlled by a clock)
- Need 2 wires, pull-up resistors, 1-10k
- 8-bit communication 
- 

## Master -> slaves 
- Need common ground
- SCL: clock
- SDA: data
- Debugging tip
  - both wires should read high when there is no data communication

## Writing 
Wadd - 0b01000000  
Example:  
Start bit  
Address for write  
Send data - Register  
Send data - Value  
Stop bit  

To make A pins outputs/inputs ->  
OUT: IODIR(0x00) set to 0x00
IN:  IODIR(0x00) set t0 0xFF

## Reading 
Radd - 0b01000001
Start bit  
Address for write  
Send req  
Restart bit  
Address for reading  
Get recieved value  
Acknowledge that we got it  
Stop bit
  