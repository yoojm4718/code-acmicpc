#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, cnt;

    cin >> N;

    for(cnt = N / 5; cnt >= 0; cnt--){
        if((N - cnt * 5) % 3) continue;
        cout << cnt + (N - cnt * 5) / 3;
        return 0;
    }

    cout << -1;

    return 0;
}