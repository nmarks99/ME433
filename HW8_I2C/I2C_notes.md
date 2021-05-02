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
  
## Using I2C library
1. Call I2C master setup (contains baud etc.)  
2. Make two functions
   - Writing
     - Start, send address, send register, send value, stop
   - Reading
     - Start, send address for writing, send register we want to read from, restart, send the address for reading, recieve, acknowledge, stop
3. Note the infinite while loop inside of the send command. This helps us know if there is a problem because we will have an LED that blinks and to show our code is running, and if it stops blinking we know the code is probably stuck in this infinite while loop, and we have to kill the power and restard to get I2C communication to start over. 