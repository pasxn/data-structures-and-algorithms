import random

def bubble_sort(arr):

  n = len(arr)

  for i in range(n - 1):
    sortedd = False
    for j in range(n - i - 1):
      if arr[j] > arr[j + 1]:
        sortedd = True;
        tmp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = tmp

    if not sorted: break

  return arr 

arr = [random.randint(1, 100) for i in range(5)]

print(f"array       : {arr}")
print(f"sorted array: {bubble_sort(arr)}")
