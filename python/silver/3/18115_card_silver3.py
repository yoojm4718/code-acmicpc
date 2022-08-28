from collections import deque

N = int(input())
skills = list(map(int, input().split()))

q = deque([])
cur = 1

for skill in skills[::-1]:
    if skill == 1:
        q.appendleft(cur)
    elif skill == 2:
        q.rotate(-1)
        q.appendleft(cur)
        q.rotate(1)
    elif skill == 3:
        q.append(cur)
        
    cur += 1

for i in q: print(i, end=" ")