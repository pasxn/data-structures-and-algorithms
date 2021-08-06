#!/usr/bin/env python3

"""
Visual representation of a graph
N E
Next E lines will contain
From -> To -> Weight

5 5
1 2 90
2 3 120
3 4 50
2 5 300
4 5 200

How to represent in computer memory

object
object
2D array of N*N as a chart (Adjacency weighted matrix)

list[][]
if i[], j[] > 0: there is an egde
"""


# if __name__ == '__main__':
    """
    make an array [N+1]*[N+1]
    input the stuff
    print the array out for the output
    travelsal
    DFS 
        Go using one path
        come back and go again
        1, 2, 3, 4, 5
        1, 2, 3, 5
        rec function with the starting and ending point
        fun (img):
            if(current = end):
                print the path
            as go foward add to the path
            loop
            coming back reduce rge path
            https://github.com/shyam3001/share/blob/Algothon/src/BasicDFS.java
            print the cost as well
            and the shorted path
            put a PR
    """