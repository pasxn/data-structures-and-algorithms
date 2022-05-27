from matplotlib import pyplot as plt
import numpy as np
import decimal

class KalmanFilter:
    def __init__(self, EST, E_est, E_mea):
        self.K_g = None
        self.E_est = E_est
        self.E_mea = E_mea
        self.EST = EST

    def compute(self, MEA):
        self.K_g = self.E_est/(self.E_est+self.E_mea)
        
        self.EST = self.EST + self.K_g*(MEA - self.EST)

        E_est = (1 - self.K_g)*self.E_est

        return self.EST

if __name__ == '__main__':

    KF = KalmanFilter(0, 0.1, 0.5)
    
    t = np.concatenate( (np.arange(0, 1, 0.001), np.arange(0, 1, 0.001)[::-1]) )

    emulated_measurement = []; output = []; sinn = [] 

    for i in range(len(t)):
        emulated_measurement.append(np.sin(t[i]) + np.random.uniform(-0.5, 0.5))
        sinn.append(np.sin(t[i]))

    for i in range(len(t)):
        output.append(KF.compute(t[i]))    

    plt.plot(emulated_measurement)
    plt.plot(output)
    plt.plot(sinn)
    plt.show()