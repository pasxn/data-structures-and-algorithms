import time 
from matplotlib import pyplot as plt 

class Propotional:
    def __init__(self, k):
        self.k = k
        self.target = 0.0
        self.location = 0.0
        self.error = 0.0
        self.velocity = 0.0
        self.prevtime = 0.0

    @staticmethod
    def findlocation(self):
        now_time = time.time()
        delta_s = self.velocity*(now_time - self.prevtime)
        self.prevtime = now_time

        return delta_s

    def compute(self, target):
        if self.prevtime == 0.0:
            self.prevtime = time.time()

        self.target = target
        location_list = list()
        velocity_list = list()

        while self.location <= self.target-0.1:
            self.error = self.target - self.location
            self.velocity = self.k*self.error 
            velocity_list.append(self.location)
            # print(self.velocity)

            self.location += self.findlocation(self)
            location_list.append(self.location)
            # print(self.location)
        
        return location_list, velocity_list


if __name__ == '__main__':

    p_con = Propotional(1)
    
    target = int(input("Enter the target: "))

    location, velocity = p_con.compute(target)

    plt.axhline(y=target, color='r', linestyle='-')
    plt.plot([i for i in range(len(location))], location)
    plt.xlabel('Time')
    plt.legend(['Target', 'Location'])
    plt.show()

    plt.axhline(y=target, color='r', linestyle='-')
    plt.plot([i for i in range(len(velocity))], velocity)
    plt.xlabel('Time')
    plt.legend(['Target', 'velocity'])
    plt.show()