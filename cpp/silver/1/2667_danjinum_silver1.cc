#include <bits/stdc++.h>

using namespace std;

int board[30][30];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<int> counts;

void bfs(int x, int y, int n){
    queue<pair<int, int>> q;
    int cx, cy, cnt = 1;

    q.push(make_pair(x, y));
    board[x][y] = 2;

    while(q.size()){
        tie(cx, cy) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            if(cx >= 0 and cx < n and cy >= 0 and cy < n and board[cx + dx[i]][cy + dy[i]] == 1){
                q.push(make_pair(cx + dx[i], cy + dy[i]));
                board[cx + dx[i]][cy + dy[i]] = 2;
                cnt++;
            }
        }
    }

    counts.push_back(cnt);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    string temp;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        for(int j = 0; j < n; j++) board[i][j] = temp[j] - '0';
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            if(board[i][j] == 1) bfs(i, j, n);

    if(not counts.size()){
        cout << 0;
        return 0;
    }
    sort(counts.begin(), counts.end());
    cout << counts.size() << "\n";
    for(int i: counts) cout << i << "\n";

    return 0;
}