from collections import deque

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    imp = list(map(int, input().split()))
    
    q = deque([])
    
    for i in range(len(imp)):
        q.append((i, imp[i]))
    
    for i in range(1, N + 1):
        idx = 0
        while True:
            max_value = max(q, key=lambda x: x[1])[1]
            cur = q.popleft()
            if cur[1] == max_value: 
                idx = cur[0]
                break
            q.append(cur)
        if idx == M:
            print(i)
            break