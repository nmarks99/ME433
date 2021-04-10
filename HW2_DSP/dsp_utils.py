import numpy as np

def get_data(sigPath):
    '''
    get_data(sigPath) imports the csv data from the paths specified in sigPath and stores 
    the signal data in a list and the time data in another list.
    '''
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
    return (sigs,ts)


def compute_FFT(sigs,ts):
    '''
    Generates a fast fourier transform of the inputted signal 
    '''
    samp_rates = [] # Compute sample rates
    for i in range(len(sigs)):
        sr = len(sigs[i])/ts[i][-1]
        samp_rates.append(sr) 

    t_fft = []
    frq_fft = []
    Y_fft = []
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

        t_fft.append(t_temp)
        frq_fft.append(frq_temp)
        Y_fft.append(Y_temp)

    return (t_fft, frq_fft, Y_fft)
    