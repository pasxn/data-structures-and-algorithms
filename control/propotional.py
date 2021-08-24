import time
from matplotlib import pyplot as plt 

# wrong!! have to reimplement after restudying the theory
class Propotional:
    def __init__(self, k, target):
        self.k = k   
        self.con_velocity = 0.0
        self.target = target
        self.curr_pos = 0.0
        self.prevtime = self.milli(self)

    @staticmethod
    def milli(self):
        return round(time.time() * 1000)

    @staticmethod
    def updatetime(self):
        self.prevtime = self.milli(self)

    def updatek(self, k):
        self.k = k

    def compute(self, input):
        self.con_velocity =  (input - self.con_velocity)*self.k
        time_diff = self.prevtime - self.milli(self)
        time.sleep(0.05)
        print(time_diff, self.milli(self))
        self.target = self.target - self.con_velocity*time_diff 
        self.updatetime(self)
        return self.target
    

if __name__ == '__main__':
    p_con = Propotional(0.1, 10)
    
    output = list()

    for i in range(0, 100):
        output.append(p_con.compute(100-i))

    plt.plot(output, [i for i in range(0, 100)])
    plt.show()

    