from matplotlib import pyplot as plt 
import numpy as np
import dsp_utils

# List with the path to each file
sigPath = [ 
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigA.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigC.csv',
    r'C:\Users\nmark\OneDrive\Documents\ME433\Python\HW2\sigD.csv'
    ]

# Open each CSV file, read it, and append to the appropriate list
(sigs,ts) = dsp_utils.get_data(sigPath)

coeffs = np.array([
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
        0.037037037037037056,
])

fir = []
for i in range(len(coeffs),len(sigs[3])):
    fir.append(coeffs * sigs[3][i-len(coeffs):i])

