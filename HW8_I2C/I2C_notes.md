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
- Start bit
- 8 bit address
- 8 bit command
- 8 bit value
- Stop bit

## Reading 
- Start bit
- 8 bit address
- 8 bit ommand
- Restart bit 
- 8 bit address
  