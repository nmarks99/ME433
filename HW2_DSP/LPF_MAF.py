from matplotlib import pyplot as plt 
import numpy as np

sigPath = [
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigC.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigD.csv'
    ]

# Open each CSV file, read it, and append to the appropriate list
sigs = []
ts = []
for i in range(len(sigPath)):
    temp_sig = []
    temp_t = []
    with open(sigPath[i]) as data:
        for row in data:
            row = row.split(',')
            temp_t.append(float(row[0]))
            temp_sig.append(float(row[1]))
        else:
            sigs.append(temp_sig)
            ts.append(temp_t)

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
samp_rates = []
for i in range(len(sigs)):
    sr = len(sigs[i])/ts[i][-1]
    samp_rates.append(sr) 

t_uf = []
frq_uf = []
Y_uf = []
for i in range(len(ts)):
    dt = 1/len(ts[i])
    t_temp = np.arange(0.0, 1.0, dt)
    
    y_temp = sigs[i]    # Unfiltered data
    Fs = samp_rates[i]
    n = len(y_temp)
    k = np.arange(n)
    T = n/Fs
    frq_temp = k/T
    frq_temp = frq_temp[range(int(n/2))]  # one side frequency range
    Y_temp = np.fft.fft(y_temp)/n         # fft computing and normalization
    Y_temp = Y_temp[range(int(n/2))]

    t_uf.append(t_temp)
    frq_uf.append(frq_temp)
    Y_uf.append(Y_temp)

# Generate FFT for the filtered data
t_f = []
frq_f = []
Y_f = []
for i in range(len(ts)):
    dt = 1/len(ts[i])
    t_temp = np.arange(0.0, 1.0, dt)
    
    y_temp = sigs_mav[i]    # Filtered data
    Fs = samp_rates[i]
    n = len(y_temp)
    k = np.arange(n)
    T = n/Fs
    frq_temp = k/T
    frq_temp = frq_temp[range(int(n/2))]  # one side frequency range
    Y_temp = np.fft.fft(y_temp)/n         # fft computing and normalization
    Y_temp = Y_temp[range(int(n/2))]

    t_f.append(t_temp)
    frq_f.append(frq_temp)
    Y_f.append(Y_temp)


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