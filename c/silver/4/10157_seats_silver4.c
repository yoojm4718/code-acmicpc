#include<stdio.h>

int main(){
    int C, R, K, i, dir = 0, x, y, nx, ny;
    int board[1000][1000];
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    scanf("%d %d", &C, &R);
    scanf("%d", &K);

    if(K > C * R) {
        printf("0");
        return 0;
    }

    x = R - 1;
    y = 0;

    for(i = 1; i < K; i++){

        board[x][y] = i;
        nx = x + dx[dir];
        ny = y + dy[dir];

        if(nx < 0 || ny < 0 || nx >= R || ny >= C || board[nx][ny]){
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    printf("%d %d", y + 1, R - x);

}