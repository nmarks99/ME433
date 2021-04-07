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
sigs_mav = []
num_avg = 1000

# Moving average
for i in range(len(sigs)):
    count = 0
    mav = 0
    temp_list = []
    for i in sigs[i]:
        if count < num_avg:
            mav = mav + i
            count += 1
        elif count == num_avg:
            count = 0
            mav = mav/num_avg
            temp_list.append(mav)
            mav = 0
    else:
        sigs_mav.append(temp_list)

for i in range(len(sigs_mav)):
    plt.figure()
    plt.plot(sigs_mav[i])
    plt.show()