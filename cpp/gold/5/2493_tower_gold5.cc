#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    stack<int> s1, s2, ans;
    int n, temp, pos;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        s1.push(temp);
    }

    for(int i = n; i >= 2; i--){
        pos = i - 1;
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        while(s1.size() and temp > s1.top()){
            s2.push(s1.top());
            s1.pop();
            pos--;
        }
        ans.push(pos);
        if(!pos) {
            s1.push(s2.top());
            s2.pop();
        }
        for(int j = 0; j < i - pos - 1; j++){
            s1.push(s2.top());
            s2.pop();
        }

        // cout << s1.top() << "\n";

        // cout << ans.size() << "\n";
    }

    ans.push(0);

    for(int i = 0; ans.size(); i++){
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}