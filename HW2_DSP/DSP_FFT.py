from matplotlib import pyplot as plt 
import numpy as np
import dsp_utils

sigPath = [
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigC.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigD.csv'
    ]

# Open each CSV file, read it, and append to the appropriate list
(sigs,ts) = dsp_utils.get_data(sigPath)

# Compute the FFT for each data set
(t, frq, Y) = dsp_utils.compute_FFT(sigs,ts)

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
