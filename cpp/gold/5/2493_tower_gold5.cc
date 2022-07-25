#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    stack<pair<int, int>> s1, s2;
    stack<int> ans;
    pair<int, int> cur;
    int n, temp;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        s2.push(make_pair(i + 1, temp));
    }

    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }

    cout << "0 ";
    cur = s1.top();
    s2.push(cur);
    s1.pop();
    while(!s1.empty()){
        if(cur.second < s1.top().second){
            while(!s2.empty() and s2.top().second < s1.top().second) s2.pop();
            if(s2.empty()) cout << "0 ";
            else cout << s2.top().first << " ";
            s2.push(s1.top());
        }
        else {
            s2.push(cur);
            cout << cur.first << " ";
        }
        cur = s1.top();
        s1.pop();
    }

    return 0;
}