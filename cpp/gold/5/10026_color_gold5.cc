#include <bits/stdc++.h>

using namespace std;

int N;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int visited_false[100][100] = { 0, };
int visited_true[100][100] = { 0, };
string board[100];

bool is_sim(char a, char b){
    if(a == b) return true;
    else{
        if(a == 'B' or b == 'B') return false;
        return true;
    }
}

int bfs_false(char color, pair<int, int> first){
    queue<pair<int, int>> q;
    int x, y, cx, cy;

    q.push(first);
    visited_false[first.first][first.second] = 1;

    while(q.size()){
        tie(x, y) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            tie(cx, cy) = make_pair(x + dx[i], y + dy[i]);

            if(cx >= 0 and cx < N and cy >= 0 and cy < N and is_sim(board[cx][cy], color) and visited_false[cx][cy] == 0){
                q.push(make_pair(cx, cy));
                visited_false[cx][cy] = 1;
            }
        }
    }

    return 1;
}

int bfs_true(char color, pair<int, int> first){
    queue<pair<int, int>> q;
    int x, y, cx, cy;

    q.push(first);
    visited_true[first.first][first.second] = 1;

    while(q.size()){
        tie(x, y) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            tie(cx, cy) = make_pair(x + dx[i], y + dy[i]);

            if(cx >= 0 and cx < N and cy >= 0 and cy < N and board[cx][cy] == color and visited_true[cx][cy] == 0){
                q.push(make_pair(cx, cy));
                visited_true[cx][cy] = 1;
            }
        }
    }

    return 1;
}

int main(){
    int cnt = 0;

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> board[i];
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(visited_true[i][j] == 0)
                cnt += bfs_true(board[i][j], make_pair(i, j));
    
    cout << cnt << " ";
    cnt = 0;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(visited_false[i][j] == 0)
                cnt += bfs_false(board[i][j], make_pair(i, j));
    
    cout << cnt;


    return 0;
}