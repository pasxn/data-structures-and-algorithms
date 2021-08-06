#!/usr/bin/env python3

import numpy as np
from matplotlib import pyplot as plt

if __name__ == '__main__':
    f = open("time.txt", "r")
    arr = list()
    
    content = f.readlines()

    for line in content:
        arr.append(float(line))

    y = np.array(arr)
    x = [i for i in range(len(y))]

    plt.plot(x, y)
    plt.show()

    f.close()