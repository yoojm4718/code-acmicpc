from collections import deque

N, M = map(int, input().split())
nums = list(map(int, input().split()))

q = deque(list(range(1, N + 1)))

cnt = 0

for target in nums:
    if len(q) == 0: cnt += 1; continue
    gap = q.index(target)
    if gap > len(q) // 2:
        q.rotate(len(q) - gap)
        q.popleft()
        cnt += len(q) - gap + 1
    else:
        q.rotate(-gap)
        q.popleft()
        cnt += gap

print(cnt)