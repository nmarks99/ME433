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
ts = [tA,tB,tC,tD]
sigs = [sigA,sigB,sigC,sigD]

# Calculate the sample rate for each data set
samp_rates = []
for i in range(len(sigs)):
    sr = len(sigs[i])/ts[i][-1]
    samp_rates.append(sr) 

# Use a Fast Fourier Transform for each data set
t = []
frq = []
Y = []
for i in range(len(ts)):
    dt = 1/len(ts[i])
    t_temp = np.arange(0.0, 1.0, dt)
    
    y_temp = sigs[i]
    Fs = samp_rates[i]
    n = len(y_temp)
    k = np.arange(n)
    T = n/Fs
    frq_temp = k/T
    frq_temp = frq_temp[range(int(n/2))]  # one side frequency range
    Y_temp = np.fft.fft(y_temp)/n         # fft computing and normalization
    Y_temp = Y_temp[range(int(n/2))]

    t.append(t_temp)
    frq.append(frq_temp)
    Y.append(Y_temp)

# Plot the data with subplots showing signal vs. time and FFT
for i in range(len(sigs)):
    fig, (ax1, ax2) = plt.subplots(2, 1)
    ax1.plot(t[i],sigs[i],'b')
    ax1.set_xlabel('Time')
    ax1.set_ylabel('Amplitude')
    ax2.loglog(frq[i],abs(Y[i]),'b') # plotting the fft
    ax2.set_xlabel('Freq (Hz)')
    ax2.set_ylabel('|Y(freq)|')
    plt.show()
