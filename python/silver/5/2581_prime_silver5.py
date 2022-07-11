def solution(M, N):
    lst = []
    
    if M == 1: M += 1
    
    for i in range(M, N + 1):
        cnt = True
        for j in range(2, i):
            if i % j == 0: cnt = False; break
        if cnt: lst.append(i)
    
    if len(lst) == 0:
        return -1
    return sum(lst), lst[0]

M = int(input())
N = int(input())

ans = solution(M, N)
if ans == -1:
    print(ans)
else:
    print(ans[0])
    print(ans[1])