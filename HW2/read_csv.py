from matplotlib import pyplot as plt 
import numpy as np

sigPath = [
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigC.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigD.csv'
    ]

tA = []; tB = []; tC = []; tD = []
sigA = []; sigB = []; sigC = []; sigD = []
with open(sigPath[0]) as dataA:
    for row in dataA:
        row = row.split(',')
        tA.append(float(row[0]))
        sigA.append(float(row[1]))

with open(sigPath[1]) as dataB:
    for row in dataB:
        row = row.split(',')
        tB.append(float(row[0]))
        sigB.append(float(row[1]))

# sample rate = number of data points / total time of samples
samp_rate = len(sigA)/tA[-1]
print('Sample Rate A = %f' % samp_rate)

# plt.figure()
# plt.plot(tA,sigA,'-b')
# plt.title('Signal A vs. Time')
# plt.xlabel('Time (s)')
# plt.ylabel('SignalA')
# plt.grid()
# plt.show()

# plt.figure()
# plt.plot(tB,sigB,'-b')
# plt.title('Signal B vs. Time')
# plt.xlabel('Time (s)')
# plt.ylabel('SignalB')
# plt.grid()
# plt.show()
