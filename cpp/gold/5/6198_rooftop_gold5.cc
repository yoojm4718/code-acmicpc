#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    stack<pair<long long, long long>> s1, s2;
    int N;
    long long temp, cnt = 0;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        s1.push(make_pair(temp, 0));
    }

    s2.push(s1.top());
    s1.pop();
    while(!s1.empty()){
        while(!s2.empty() and s1.top().first > s2.top().first){
            s1.top().second++;
            s1.top().second += s2.top().second;
            s2.pop();
        }
        cnt += s1.top().second;
        s2.push(s1.top());
        s1.pop();
    }

    cout << cnt;

    return 0;
}