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

# Coefficients from https://fiiir.com/

coeffs = np.array([
0.000000000000000000,
-0.000016817461869098,
-0.000041826483687530,
0.000052911264300492,
0.000312583169239523,
0.000452184140972260,
-0.000000000000000001,
-0.001067909719026748,
-0.001809550814670827,
-0.000822697450880302,
0.002137678239328250,
0.004870011274428794,
0.003769244006115367,
-0.002572442672826673,
-0.010155915286819240,
-0.010974888508867891,
0.000000000000000006,
0.017364880107313452,
0.025566712253050173,
0.010424812183889264,
-0.025066651678255975,
-0.054737591234933436,
-0.042477128339528714,
0.031061127410725618,
0.147771500511120618,
0.255967494614855406,
0.299984560952054335,
0.255967494614855406,
0.147771500511120646,
0.031061127410725618,
-0.042477128339528734,
-0.054737591234933443,
-0.025066651678255975,
0.010424812183889264,
0.025566712253050183,
0.017364880107313466,
0.000000000000000006,
-0.010974888508867893,
-0.010155915286819250,
-0.002572442672826673,
0.003769244006115366,
0.004870011274428800,
0.002137678239328250,
-0.000822697450880304,
-0.001809550814670833,
-0.001067909719026749,
-0.000000000000000001,
0.000452184140972260,
0.000312583169239523,
0.000052911264300492,
-0.000041826483687530,
-0.000016817461869097,
0.000000000000000000,
])

fir = []
for j in range(len(sigs)):
    temp_fir = []
    for i in range(len(coeffs),len(sigs[j])):
        temp_fir.append(sum(coeffs*sigs[j][i-len(coeffs):i]))
    else:
        fir.append(temp_fir)

# Compute the FFT for the unfiltered and filtered signals
(t,frq,y) = dsp_utils.compute_FFT(sigs,ts)
(tfir,frqfir,yfir) = dsp_utils.compute_FFT(fir,ts)


'''
fig, ax = plt.subplots()
ax.loglog(frq[3],abs(y[3]),'k')
ax.loglog(frqfir[3],abs(yfir[3]),'r')
ax.grid()
plt.show()
'''

fig,ax = plt.subplots()
ax.plot(sigs[3],'k')
ax.plot(fir[3],'r')
plt.show()