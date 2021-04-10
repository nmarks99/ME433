import dsp_utils
from matplotlib import pyplot as plt

sigPath = [
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigC.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigD.csv'
    ]

(sigs,ts) = dsp_utils.get_data(sigPath)

(t_fft,frq_fft,Y_fft) = dsp_utils.compute_FFT(sigs,ts)

