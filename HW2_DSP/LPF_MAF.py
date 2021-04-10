from matplotlib import pyplot as plt 
import numpy as np
import dsp_utils

sigPath = [
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigC.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigD.csv'
    ]

# Read in the CSV data
(sigs,ts) = dsp_utils.get_data(sigPath)

# Low pass filter the data with a moving average 
sigs_mav = []
num_avg = [300,300,1,25]
for k in range(len(sigs)):
    temp_mav = []
    i = 0
    while i < (len(sigs[k]) - num_avg[k] + 1):
        reg = sigs[k][i:i+num_avg[k]]
        mav = sum(reg)/num_avg[k]
        temp_mav.append(mav)
        i += 1
    sigs_mav.append(temp_mav)

# Make time values for the plots
mavt = []
j = 0
for i in ts:
    mavt.append(i[num_avg[j]-1:])
    j += 1

# Plot filtered and unfiltered data together
ttl = ['Num avg = '+str(num_avg[0]),
       'Num avg = '+ str(num_avg[1]),
       'Num avg = '+ str(num_avg[2]),
       'Num avg = '+ str(num_avg[3])
]
for i in range(len(sigs)):
    fig,ax = plt.subplots()
    ax.plot(ts[i],sigs[i],'-k',label='Unfiltered')
    ax.plot(mavt[i],sigs_mav[i],'-r',label='Filtered')
    ax.legend()
    ax.set(xlabel='Time (s)', ylabel='Signal A',title=ttl[i])
    ax.grid()
    plt.show()


# Generate FFT of the unfiltered data
(t_uf, frq_uf, Y_uf) = dsp_utils.compute_FFT(sigs,ts)

# Generate FFT for the filtered data
(t_f, frq_f, Y_f) = dsp_utils.compute_FFT(sigs_mav,ts)



# Plot them both on the same axis
ttl = ['FFT A, num avg = '+ str(num_avg[0]),
       'FFT B, num avg = '+ str(num_avg[1]),
       'FFT C, num avg = '+ str(num_avg[2]),
       'FFT D, num avg = '+ str(num_avg[3])
    ]

for i in range(len(sigs)):
    fig,ax = plt.subplots()
    ax.loglog(frq_uf[i],abs(Y_uf[i]),'-k',label='Unfiltered')
    ax.loglog(frq_f[i],abs(Y_f[i]),'-r',label='Filtered')
    ax.legend()
    ax.set(xlabel='Time (s)', ylabel='Y|Y(freq)|',title=ttl[i])
    ax.grid()
    plt.show()