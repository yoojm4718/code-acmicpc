#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int F, S, G, U, D, cur, cur_cnt, temp;
    bool visited[1000001] = { 0, };
    queue<pair<int, int>> q;

    cin >> F >> S >> G >> U >> D;

    q.push(make_pair(S, 0));
    visited[S] = true;
    while(q.size()){
        tie(cur, cur_cnt) = q.front();
        q.pop();

        if(cur == G) {
            cout << cur_cnt;
            return 0;
        }

        temp = cur + U;
        if(temp > 0 and temp <= F and !visited[temp]){
            q.push(make_pair(temp, cur_cnt + 1));
            visited[temp] = true;
        }

        temp = cur - D;
        if(temp > 0 and temp <= F and !visited[temp]){
            q.push(make_pair(temp, cur_cnt + 1));
            visited[temp] = true;
        }
    }

    cout << "use the stairs";

    return 0;
}