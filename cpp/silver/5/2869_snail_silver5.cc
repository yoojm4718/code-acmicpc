#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int A, B, V, cnt;

    cin >> A >> B >> V;

    cnt = (int)((double)(V - A) / (A - B) + 1);

    if((V - A) % (A - B)) cnt++;

    cout << cnt;

    return 0;
}