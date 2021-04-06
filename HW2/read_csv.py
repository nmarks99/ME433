from matplotlib import pyplot as plt 
import numpy as np

sigPath = [
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigC.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigD.csv'
    ]

# Creates some lists to store the data
tA = []; tB = []; tC = []; tD = []
sigA = []; sigB = []; sigC = []; sigD = []

# Open each CSV file, read it, and append to the appropriate list
# Probably a more efficient way of doing this but this works fine
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
with open(sigPath[2]) as dataC:
    for row in dataC:
        row = row.split(',')
        tC.append(float(row[0]))
        sigC.append(float(row[1]))
with open(sigPath[3]) as dataD:
    for row in dataD:
        row = row.split(',')
        tD.append(float(row[0]))
        sigD.append(float(row[1]))

t = [tA,tB,tC,tD]
sigs = [sigA,sigB,sigC,sigD]

# sample rate = number of data points / total time of samples
samp_rates = []
for i in range(len(sigs)):
    sr = len(sigs[i])/t[i][-1]
    samp_rates.append(sr)
print(samp_rates)

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
