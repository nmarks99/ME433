from matplotlib import pyplot as plt 
import numpy as np

# List with the path to each file
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





