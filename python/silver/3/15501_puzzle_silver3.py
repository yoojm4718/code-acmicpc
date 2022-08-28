from collections import deque

N = int(input())

arr1 = list(map(int, input().split()))
arr2 = list(map(int, input().split()))

q = deque(arr1)
q.rotate(-q.index(arr2[0]))
if list(q) == arr2:
    print("good puzzle")
    exit()
    
q = deque(arr1[::-1])
q.rotate(-q.index(arr2[0]))
if list(q) == arr2:
    print("good puzzle")
    exit()

print("bad puzzle")

