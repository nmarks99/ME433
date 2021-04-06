from matplotlib import pyplot as plt 
import numpy as np

sigPath = [
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigC.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigD.csv'
    ]

t = []
sigA = []
with open(sigPath[1]) as dataA:
    for row in dataA:
        row = row.split(',')
        t.append(float(row[0]))
        sigA.append(float(row[1]))


plt.figure()
plt.plot(t,sigA,'-b')
plt.title('Signal A vs. Time')
plt.xlabel('Time (s)')
plt.ylabel('SignalA')
plt.grid()
plt.show()
