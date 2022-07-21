#include <bits/stdc++.h>

using namespace std;

string board[1000];
int visited[1000][1000] = { 0, };
int visited_fire[1000][1000] = { 0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void next_fire(int w, int h){
    queue<pair<int, int>> q;
    bool flag = true;
    int x, y, cx, cy;

    for(int i = 0; i < h and flag; i++)
        for(int j = 0; j < w and flag; j++)
            if(board[i][j] == '*'){
                q.push(make_pair(i, j));
                visited_fire[i][j] = 1;
                flag = false;
            }
    
    while(q.size()){
        tie(x, y) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            tie(cx, cy) = make_pair(x + dx[i], y + dy[i]);

            if(board[cx][cy] == '.'){
                board[cx][cy] = '*';
                visited_fire[cx][cy] = 1;
            }

            if(cx >= 0 and cx < h and cy >= 0 and cy < w and board[cx][cy] == '*' and visited_fire[cx][cy] == 0){
                visited_fire[cx][cy] = 1;
                q.push(make_pair(cx, cy));
            }
        }
    }

    memset(visited_fire, 0, sizeof(visited_fire));
}

int bfs(int w, int h){
    queue<tuple<int, int, int>> q;
    
    int x, y, cx, cy, cnt, cur_cnt = 0;
    bool flag = true;


    for(int i = 0; i < h and flag; i++)
        for(int j = 0; j < w and flag; j++)
            if(board[i][j] == '@'){
                if(i == 0 or i == h - 1 or j == 0 or j == w - 1) return 1;
                q.push(make_tuple(i, j, 0));
                visited[i][j] = 1;
                board[i][j] = '.';
                flag = false;
            }
    
    // for(int i = 0; i < h; i++)
    //     cout << board[i] << "\n";
    
    while(q.size()){
        // cout << get<0>(q.front()) << "," << get<1>(q.front()) << "\n";

        tie(x, y, cnt) = q.front();
        q.pop();

        if(cur_cnt++ < cnt + 1)
            next_fire(w, h);

        // for(int i = 0; i < h; i++)
        //     cout << board[i] << "\n";

        for(int i = 0; i < 4; i++){
            tie(cx, cy) = make_pair(x + dx[i], y + dy[i]);

            if(cx < 0 or cx >= h or cy < 0 or cy >= w)
                return cnt + 1;

            if(board[cx][cy] == '.' and visited[cx][cy] == 0){
                visited[cx][cy] = 1;
                q.push(make_tuple(cx, cy, cnt + 1));
            }
        }
    }

    return -1;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, w, h, res;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> w >> h;

        for(int j = 0; j < h; j++)
            cin >> board[j];
        
        res = bfs(w, h);
        memset(visited, 0, sizeof(visited));
        if(res == -1){
            cout << "IMPOSSIBLE" << "\n";
            continue;
        }
        cout << res << "\n";
    }

    return 0;
}