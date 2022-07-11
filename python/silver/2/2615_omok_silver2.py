N = 19

dx = [1, 1, 0, -1]
dy = [0, 1, 1, 1]

def omok(board):
    win = 0
    winx = -1
    winy = -1
    cur = 0
    
    for x in range(N):
        for y in range(N):
            if board[x][y]:
                cur = board[x][y]
                
                for i in range(4):
                    cnt = 1
                    cx, cy = x + dx[i], y + dy[i]
                    rx, ry = x - dx[i], y - dy[i]
                    
                    while cx < N and -1 < cy < N:
                        if board[cx][cy] == cur:
                            cnt += 1
                        else: break
                        cx += dx[i]
                        cy += dy[i]
                        
                    if cnt != 5 or (-1 < rx < N and -1 < ry < N and board[rx][ry] == cur): continue
                    
                    win = cur
                    winx = x + 1
                    winy = y + 1
                    break
        if win != 0:
            break
    
    return (win, winx, winy)

board = []

for i in range(N):
    board.append(list(map(int, input().split())))

win, winx, winy = omok(board)

print(win)
if win != 0: print(f"{winx} {winy}")