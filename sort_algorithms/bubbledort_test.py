def bubblesort(arr):
    swapped = 0
    lst = list()
    coms = 0
    print(arr)
    print("---------------------------------")
    for i in range(0, len(arr) - 1):
        coms = 0
        swapped = 0
        for j in range(0, len(arr) - i - 1):
                coms+=1
                if arr[j] > arr[j+1]:
                    temp = arr[j]
                    arr[j] = arr[j + 1]
                    arr[j + 1] = temp
                    swapped = 1  
        print(arr)
        lst.append(coms)
        if swapped != 1:
            break
    print("---------------------------------")
    print(lst)

if __name__ == '__main__':
    arr = [21, 2, 43, 24, 15, 36, 87, 8]
    bubblesort(arr)