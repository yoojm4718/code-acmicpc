from collections import deque

N, K = map(int, input().split())

deq = deque(range(N))

print("<", end="")
while len(deq) > 1:
    deq.rotate(-K + 1)
    item = deq.popleft()
    print(f"{item + 1}, ", end="")
print(f"{deq.popleft() + 1}>", end="")