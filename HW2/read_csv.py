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
# Store time and signal data in lists
t = [tA,tB,tC,tD]
sigs = [sigA,sigB,sigC,sigD]

# Calculate the sample rate for each data set
samp_rates = []
for i in range(len(sigs)):
    sr = len(sigs[i])/t[i][-1]
    samp_rates.append(sr)
# print('Sample Rate A = %.3f Hz' % samp_rates[0])
# print('Sample Rate B = %.3f Hz' % samp_rates[1])    
# print('Sample Rate C = %.3f Hz' % samp_rates[2])    
# print('Sample Rate D = %.3f Hz' % samp_rates[3])        

# Filter the data using a Fast Fourier Transform
'''
dt = 1.0/50000.0            # 50kHz
t = np.arange(0.0, 1.0, dt) # 5s
y = sigs[0]
Fs = samp_rates[0]
n = len(y)                  # length of the signal
k = np.arange(n)
T = n/Fs
frq = k/T                   # two sides frequency range
frq = frq[range(int(n/2))]  # one side frequency range
Y = np.fft.fft(y)/n         # fft computing and normalization
Y = Y[range(int(n/2))]

# Plot the signal vs. time and FFT on subplots
fig, (ax1, ax2) = plt.subplots(2, 1)
ax1.plot(t,y,'b')
ax1.set_xlabel('Time')
ax1.set_ylabel('Amplitude')
ax2.loglog(frq,abs(Y),'b') # plotting the fft
ax2.set_xlabel('Freq (Hz)')
ax2.set_ylabel('|Y(freq)|')
plt.show()
'''

t = []
y = []
frq = []
Y = []
#for i in range(len(t)):
