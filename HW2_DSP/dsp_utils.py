
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
