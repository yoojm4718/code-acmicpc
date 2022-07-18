#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[100001] = { 0 };
    int dx[3] = { 1, -1 };
    int N, K, cur, cnt, d, res;
    queue<pair<int, int>> q;

    cin >> N >> K;

    q.push(make_pair(N, 0));
    arr[N] = 1;

    while(q.size()){
        tie(cur, cnt) = q.front();
        q.pop();

        if(cur == K){
            res = cnt;
            break;
        }

        dx[2] = cur;

        for(int i = 0; i < 3; i++){
            d = cur + dx[i];
            if(d >= 0 and d <= 100000 and arr[d] == 0){
                q.push(make_pair(d, cnt + 1));
                arr[d] = 1;
            }
        }

    }

    cout << res;

    return 0;
}



