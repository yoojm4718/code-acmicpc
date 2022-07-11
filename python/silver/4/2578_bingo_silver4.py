N = 5
dx = [1, 1, 0, -1]
dy = [0, 1, 1, 1]

board = []
calls = []
bingo_cnt = 0

def check_line(cx, cy, i):
    global board, bingo_cnt
    cnt0 = 0
    cnt1 = 0
    for n in range(4):
        cx += dx[i]
        cy += dy[i]
        if board[cx][cy] == -1: cnt1 += 1
        elif board[cx][cy] == 0: cnt0 += 1
        else: break
    if cnt0 + cnt1 == 4 and cnt0 > 0:
        bingo_cnt += 1
        for _ in range(5):
            board[cx][cy] = -1
            cx -= dx[i]
            cy -= dy[i]

def bingo(call):
    global dx, dy, board, bingo_cnt
    for x in range(N):
        for y in range(N):
            if board[x][y] == call: board[x][y] = 0
    
    for x in range(N):
        y = 0
        if board[x][y] == 0 or board[x][y] == -1:
            if x == 0:
                for i in range(3):
                    check_line(x, y, i)
            elif x == 4:
                for i in range(2, 4):
                    check_line(x, y, i)
            else:
                check_line(x, y, 2)
    
    for y in range(1, N):
        x = 0
        if board[x][y] == 0 or board[x][y] == -1:
            check_line(x, y, 0)

for _ in range(N):
    board.append(list(map(int, input().split())))

for _ in range(N):
    for i in input().split(): calls.append(int(i))

for i in range(len(calls)):
    bingo(calls[i])
    if bingo_cnt >= 3:
        print(i + 1)
        break
    
    # print(i + 1, bingo_cnt)
    # for j in range(N):
    #     print(board[j])