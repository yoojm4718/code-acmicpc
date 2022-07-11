from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

M, N, K = map(int, input().split())

board = [[0 for _ in range(N)] for _ in range(M)]
rects = []

for _ in range(K):
    y1, x1, y2, x2 = map(int, input().split())
    rects.append(((x1, y1), (x2, y2)))

def is_rect(x, y):
    for start, end in rects:
        if start[0] <= x < end[0] and start[1] <= y < end[1]:
            return True
    return False

def is_checked(x, y):
    if board[x][y] == 1: return True
    return False

def is_bound(x, y):
    if (x < 0 or x >= M) or (y < 0 or y >= N): return True
    return False

def is_possible(x, y):
    if is_bound(x, y) or is_rect(x, y) or is_checked(x, y):
        return False
    return True

'''
def bfs(x, y):
    queue = deque([])
    queue.append((x, y))
    cnt = 0
    while queue:
        cur_x, cur_y = queue.popleft()
        board[cur_x][cur_y] = 1
        cnt += 1
        for i in range(4):
            check_x, check_y = cur_x + dx[i], cur_y + dy[i]
            if is_possible(check_x, check_y) and ((check_x, check_y) not in queue):
                queue.append((check_x, check_y))
    
    return cnt
'''

def dfs(x, y):
    stack = []
    stack.append((x, y))
    cnt = 0
    while stack:
        cur_x, cur_y = stack.pop()
        board[cur_x][cur_y] = 1
        cnt += 1
        for i in range(4):
            check_x, check_y = cur_x + dx[i], cur_y + dy[i]
            if is_possible(check_x, check_y) and ((check_x, check_y) not in stack):
                stack.append((check_x, check_y))
    
    return cnt

def solution(M, N):
    areas = []
    
    for i in range(M):
        for j in range(N):
            if not(is_rect(i, j) or is_checked(i, j)):
                cnt = dfs(i, j)
                areas.append(cnt)
                
    return areas

areas = solution(M, N)
print(len(areas))
for i in sorted(areas): print(i, end=" ")