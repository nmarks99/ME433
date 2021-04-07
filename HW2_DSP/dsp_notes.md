# Notes on Digital Signal Processing

## Moving average filter(MAF):
- Greater number of points to average
  - Smoother
  - Greater lag (time between when something changes and when you can detect when it changes)
  
## Infinite Impulse Response Filter (IIR):
- filtered output = (prev filt out) $\cdot$ A + (new data out)$\cdot$ B
- A + B = 1
- Choose A and B 

## Finite Impulse Response Filter (FIR):
- MAF is a *special case* of this. 
- out[i] = c0 $\cdot$(data[i]) + c1$\cdot$(data[-1])...
- $\sum$c = 1
  - For MAF, all the c values are the same, so divide by the number of data points you are summing. For the FIR not all the c values are the same.