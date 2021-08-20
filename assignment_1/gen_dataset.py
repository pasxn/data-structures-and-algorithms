import random
import sys

if __name__ == '__main__':
    filename = sys.argv[1]
    length = int(sys.argv[2])
    f = open(filename, "w")
    
    for i in range(length):
        val = random.randint(0, length*2)
        f.write(str(val))
        f.write(" ")
    
    f.close()