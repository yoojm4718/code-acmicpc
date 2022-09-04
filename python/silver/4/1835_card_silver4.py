from collections import deque

N = int(input())

last = list(range(N, 0, -1))
first = deque([])

for i in last:
    first.append(i)
    first.rotate(-i)

print(*list(first)[::-1], sep=" ")