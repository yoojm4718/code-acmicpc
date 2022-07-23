#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    if(n == 1) return false;
    else if(n >= 2 and n < 4) return true;
    else{
        for(int i = 2; i <= sqrt(n); i++)
            if(n % i == 0) return false;
        return true;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, temp, cnt = 0;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> temp;
        if(is_prime(temp)) cnt++;
    }

    cout << cnt;

    return 0;
}