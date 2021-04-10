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
        -0.000011466433343440,
        -0.000048159680438716,
        -0.000070951498745996,
        0.000000000000000000,
        0.000226394896924650,
        0.000570593070542985,
        0.000843882357908127,
        0.000742644459879189,
        -0.000000000000000001,
        -0.001387330856962112,
        -0.002974017320060804,
        -0.003876072294410999,
        -0.003078546062261788,
        0.000000000000000002,
        0.004911281747189231,
        0.009897689392343489,
        0.012239432700612913,
        0.009302643950572093,
        -0.000000000000000005,
        -0.013947257358995015,
        -0.027649479941983943,
        -0.034045985830080311,
        -0.026173578588735643,
        0.000000000000000007,
        0.043288592274982135,
        0.096612134128292462,
        0.148460098539443669,
        0.186178664190551207,
        0.199977588313552862,
        0.186178664190551235,
        0.148460098539443669,
        0.096612134128292462,
        0.043288592274982128,
        0.000000000000000007,
        -0.026173578588735653,
        -0.034045985830080325,
        -0.027649479941983936,
        -0.013947257358995019,
        -0.000000000000000005,
        0.009302643950572094,
        0.012239432700612920,
        0.009897689392343489,
        0.004911281747189235,
        0.000000000000000002,
        -0.003078546062261790,
        -0.003876072294411004,
        -0.002974017320060808,
        -0.001387330856962112,
        -0.000000000000000001,
        0.000742644459879189,
        0.000843882357908127,
        0.000570593070542984,
        0.000226394896924650,
        0.000000000000000000,
        -0.000070951498745996,
        -0.000048159680438716,
        -0.000011466433343440,
        0.000000000000000000,
])
fir = []
for j in range(len(sigs)):
    temp_fir = []
    for i in range(len(coeffs),len(sigs[j])):
        temp_fir.append(sum(coeffs*sigs[j][i-len(coeffs):i]))
    else:
        fir.append(temp_fir)


(t,frq,y) = dsp_utils.compute_FFT(sigs,ts)
(tfir,frqfir,yfir) = dsp_utils.compute_FFT(fir,ts)

fig, ax = plt.subplots()
ax.loglog(frq[3],abs(y[3]),'k')
ax.loglog(frqfir[3],abs(yfir[3]),'r')
plt.show()