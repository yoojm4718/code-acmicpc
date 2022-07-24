#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    stack<int> s1, s2, ans;
    int n, temp;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        s1.push(temp);
    }

    for(int i = 1; i <= n; i++){
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        while(s1.size() and temp > s1.top()){
            s2.push(s1.top());
            s1.pop();
        }
        ans.push(s1.size());
        while(s2.size() > i){
            s1.push(s2.top());
            s2.pop();
        }
    }

    while(ans.size()){
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}