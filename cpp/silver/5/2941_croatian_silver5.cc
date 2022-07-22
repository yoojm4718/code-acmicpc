#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    int cnt = 0;

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        cnt++;
        switch (s[i])
        {
        case 'c':
            if(s[i + 1] == '=' or s[i + 1] == '-') i++;
            break;
        case 'd':
            if(s[i + 1] == '-') i++;
            else if(s[i + 1] == 'z' and s[i + 2] == '=') i += 2;
            break;
        case 'l':
        case 'n':
            if(s[i + 1] == 'j') i++;
            break;
        case 's':
        case 'z':
            if(s[i + 1] == '=') i++;
            break;
        
        default:
            break;
        }
    }

    cout << cnt;

    return 0;
}