# ST7789 Display
- Uses SPI communication
## Connections 
GND -> GND  
VCC -> 3.3V  
SCL -> SCK2 (pin 26)  
SDA -> SDO   
RES -> PIN  
DC -> PIN  
BLK -> NC

This display is a matrix of "windows" , 240x240 pixels and one bright light behind it all. It is capable of tinting an individual pixel to be a certain color.  

To set certain pixels to certain colors, we will need to supply the RGB value for each pixel.
* RGB value takes up 2 bytes
* Total amount of data = 240 x 240 x 2 = 115200
  * This will take a while and with the amount of RAM we have on our PIC, we can't even store enough data to send an entire image, but instead must draw as we go.  
  
## Function to draw text to the display
`void drawChar(unsigned short x,unsigned short y,unsigned short color,unsigned char letter)`  
`ascii[letter][i], for i = 0:4`  
Note that printable characters in ascii start at 0x20, so for really you would need to do (letter - 0x20)  

`x,y` would be the position at the top left  

Then you can use another function to draw a string:  
`void drawString(x,y,color,char *m)`  
* Loop through m calling `drawChar`
* `char m[20]`
* sprintf(m,"hello")
* drawString(20,20,BLUE,m)
* Every time you draw a new character, you need to shift x over by 5 (x+i*5) 