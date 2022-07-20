#include <bits/stdc++.h>

using namespace std;

string board[1000];
string check_board[1000];
int visited[1000][1000] = { 0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void next_fire(int w, int h){
    vector<pair<int, int>> will_burn;
    int x, y, cx, cy;

    for(int j = 0; j < h; j++)
        for(int k = 0; k < w; k++)
            if(check_board[j][k] == '*') will_burn.push_back(make_pair(j, k));
    
    for(pair<int, int> j: will_burn){
        tie(x, y) = j;

        for(int k = 0; k < 4; k++){
            tie(cx, cy) = make_pair(x + dx[k], y + dy[k]);
            if(check_board[cx][cy] == '.' and cx >= 0 and cx < h and cy >= 0 and cy < w)
                check_board[cx][cy] = '*';
        }
    }
}

int bfs(int w, int h){
    queue<tuple<int, int, int>> q;
    
    int x, y, cx, cy, cnt, cur_cnt = 0;
    bool flag = true;


    for(int i = 0; i < h and flag; i++)
        for(int j = 0; j < w and flag; j++)
            if(board[i][j] == '@'){
                q.push(make_tuple(i, j, 0));
                visited[i][j] = 1;
                board[i][j] = '.';
                flag = false;
            }
    
    for(int i = 0; i < h; i++)
        check_board[i] = board[i];
    
    // for(int i = 0; i < h; i++)
    //     cout << board[i] << endl;
    
    while(q.size()){
        // cout << get<0>(q.front()) << "," << get<1>(q.front()) << endl;

        tie(x, y, cnt) = q.front();
        q.pop();

        if(cur_cnt++ < cnt + 1)
            next_fire(w, h);

        // for(int i = 0; i < h; i++)
        //     cout << check_board[i] << endl;

        for(int i = 0; i < 4; i++){
            tie(cx, cy) = make_pair(x + dx[i], y + dy[i]);

            if(cx < 0 or cx >= h or cy < 0 or cy >= w)
                return cnt + 1;

            if(check_board[cx][cy] == '.' and visited[cx][cy] == 0){
                visited[cx][cy] = 1;
                q.push(make_tuple(cx, cy, cnt + 1));
            }
        }
    }

    return -1;

}

int main(){
    int T, w, h, res;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> w >> h;

        for(int j = 0; j < h; j++)
            cin >> board[j];
        
        res = bfs(w, h);
        memset(visited, 0, sizeof(visited));
        if(res == -1){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << res << endl;
    }

    return 0;
}