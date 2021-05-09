# WS2812B Neopixels
## Timer
Recall the formula below for setting up timers on the PIC32 at a desired frequency:
$$
\frac{48 MHz}{f} = (PR1 + 1) * N
$$
  
48 MHz is the system clock speed of the PIC32  
*f* = desired frequency
*N* = Prescaler  
*PR1* = maximum value of the count of TMRx before it resets
to zero on the next count.
