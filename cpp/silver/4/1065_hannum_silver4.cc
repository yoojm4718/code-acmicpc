#include <bits/stdc++.h>

using namespace std;

bool is_han_number(int n){
    bool flag = true;
    int temp, d;

    if(n / 10 == 0 or n / 100 == 0) return flag;

    temp = n % 10;
    n /= 10;
    d = n % 10 - temp;
    while(true){
        temp = n % 10;
        n /= 10;
        if(!n) break;
        if(d != n % 10 - temp){
            flag = false;
            break;
        }
        d = n % 10 - temp;
    }

    return flag;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, cnt = 0;

    cin >> N;

    for(int i = 1; i <= N; i++)
        if(is_han_number(i)) cnt += 1;
    
    cout << cnt;

    return 0;
}