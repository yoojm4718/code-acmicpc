#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    stack<pair<int, int>> s1, s2;
    stack<int> ans;
    int N, temp;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> temp;
        s1.push(make_pair(temp, -1));
    }

    s2.push(s1.top());
    ans.push(s1.top().second);
    s1.pop();
    while(!s1.empty()){
        while(!s2.empty() and s1.top().first >= s2.top().first) s2.pop();
        if(!s2.empty()) s1.top().second = s2.top().first;
        ans.push(s1.top().second);
        s2.push(s1.top());
        s1.pop();
    }

    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}