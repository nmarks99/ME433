# ST7789 Display
- Uses SPI communication
## Connections 
GND -> GND  
VCC -> 3.3V  
SCL -> SCK  
SDA -> SDO   
RES -> PIN  
DC -> PIN  
BLK -> NC

This display is a matrix of "windows" , 240x240 pixels and one bright light behind it all. It is capable of tinting an individual pixel to be a certain color.  

To set certain pixels to certain colors, we will need to supply the RGB value for each pixel.
* RGB value takes up 2 bytes
* Total amount of data = 240 x 240 x 2 = 115200
  * This will take a while and with the amount of RAM we have on our PIC, we can't even store enough data to send an entire image, but instead must draw as we go.