from collections import deque

N = int(input())
q = deque(enumerate(list(map(int, input().split()))))

while q:
    temp = q.popleft()
    print(temp[0] + 1, end=" ")
    if temp[1] > 0: q.rotate(-(temp[1] - 1))
    else: q.rotate(-temp[1])