#include <bits/stdc++.h>

using namespace std;

int board[1000][1000];
bool visited[1000][1000];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs(int n, int m){
    queue<tuple<int, int, int>> q;
    int x, y, cnt, cx, cy;

    memset(visited, 0, sizeof(visited));
    q.push(make_tuple(0, 0, 1));
    visited[0][0] = true;

    while(q.size()){
        tie(x, y, cnt) = q.front();
        q.pop();

        if(x == n - 1 and y == m - 1) return cnt;

        for(int i = 0; i < 4; i++){
            tie(cx, cy) = make_pair(x + dx[i], y + dy[i]);

            if(cx >= 0 and cx < n and cy >= 0 and cy < m and !visited[cx][cy] and board[cx][cy] == 0){
                q.push(make_tuple(cx, cy, cnt + 1));
                visited[cx][cy] = true;
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m, temp;
    string str;
    vector<int> v;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < m; j++) board[i][j] = str[j] - '0';
    }

    temp = bfs(n, m);
    if(temp != -1) v.push_back(temp);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 1){
                board[i][j] = 0;
                temp = bfs(n, m);
                if(temp != -1) v.push_back(temp);
                board[i][j] = 1;
            }
        }
    }

    if(v.size()) cout << *max_element(v.begin(), v.end());
    else cout << "-1";

    return 0;
}