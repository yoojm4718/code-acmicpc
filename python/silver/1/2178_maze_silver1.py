from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

n, m = map(int, input().split())
maze = []
res = []
visited = [[False for i in range(m)] for j in range(n)]
for _ in range(n):
    maze.append(list(map(int, input())))

def bfs():
    global maze, res, visited, dx, dy
    
    queue = deque([])
    
    x, y = 0, 0
    queue.append((x, y, 1))
    visited[x][y] = True
    
    while queue:
        x, y, cnt = queue.popleft()
        
        if x == n - 1 and y == m - 1:
            res.append(cnt)
        
        for i in range(4):
            cx = x + dx[i]
            cy = y + dy[i]
            if -1 < cx < n and -1 < cy < m and maze[cx][cy] == 1 and not visited[cx][cy]:
                queue.append((cx, cy, cnt + 1))
                visited[cx][cy] = True

bfs()
print(min(res))
