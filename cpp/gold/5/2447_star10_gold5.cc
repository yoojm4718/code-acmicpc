#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> board;

void recursion(int n, int x, int y){
    if(n == 1){
        board[x][y] = '*';
        return;
    }

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(not(i == 1 and j == 1)) recursion(n / 3, x + i * (n / 3), y + j * (n / 3));
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        vector<char> temp;
        for(int j = 0; j < n; j++)
            temp.push_back(' ');
        board.push_back(temp);
    }

    recursion(n, 0, 0);

    for(int i = 0; i < board.size(); i++){
        for(char j: board[i]) cout << j;
        cout << "\n";
    }
    
    return 0;
}