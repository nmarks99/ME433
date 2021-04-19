# UART 
## Digital communication protocol (Universal Asynchronous Recieve and Transmitt) 
- Simple
- Slow
- Uses few pins

### Transmission
 - Tx (Transmitt, output) -> Rx (Recieve, input)
 - Baud rate is bits per second data rate and tells each device when to read the data. 
   - Baud = 115200 means 11,520 bits/sec
   - Both devices must have the same baud rate
 - Hardware handshaking to get guarenteed correct data trasmition 
   - CTS (clear to send)
   - RTS (ready to transmitt)
  
### CP2104
- Talks to UART, sends data over USB