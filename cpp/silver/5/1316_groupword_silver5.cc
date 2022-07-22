#include <bits/stdc++.h>

using namespace std;

bool group_check(string s){
    vector<char> v;
    char cur = 0;

    for(char i: s){
        if(cur != i){
            cur = i;
            auto search = find(v.begin(), v.end(), i);
            if(search != v.end()) return false;
            else v.push_back(i);
        }
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, cnt = 0;
    string s;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> s;
        if(group_check(s)) cnt++;
    }

    cout << cnt;

    return 0;
}