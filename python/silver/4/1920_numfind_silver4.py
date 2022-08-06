N = int(input())

A = list(map(int, input().split()))
A.sort()

M = int(input())

nums = list(map(int, input().split()))

for i in nums:
    low = 0
    high = len(A) - 1
    flag = False
    
    while low <= high:
        mid = (low + high) // 2
        if i == A[mid]: flag = True; break
        elif i > A[mid]: low = mid + 1
        else: high = mid - 1
    
    if flag: print(1)
    else: print(0)