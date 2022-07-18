#include <bits/stdc++.h>

using namespace std;

int board[500][500] = { 0, };
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int n, int m, pair<int, int> first){
    queue<pair<int, int>> q, cur;
    int x, y, cx, cy, cnt = 0;

    q.push(first);
    board[first.first][first.second] = 2;

    while(q.size()){
        tie(x, y) = q.front();
        q.pop();
        cnt++;

        for(int i = 0; i < 4; i++){
            tie(cx, cy) = make_pair(x + dx[i], y + dy[i]);
            if(cx >= 0 and cx < n and cy >= 0 and cy < m and board[cx][cy] == 1){
                q.push(make_pair(cx, cy));
                board[cx][cy] = 2;
            }
        }
    }

    return cnt;
}

int main(){
    int n, m;
    vector<int> counts;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] == 1)
                counts.push_back(bfs(n, m, make_pair(i, j)));
    
    cout << counts.size() << endl;

    if(counts.size())
        cout << *max_element(counts.begin(), counts.end());
    else cout << 0;

    return 0;
}