#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n){
    if(n == 1) return false;
    else if(n >= 2 and n < 4) return true;
    else{
        for(int i = 2; i * i <= n; i++)
            if(n % i == 0) return false;
        return true;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int M, N, cnt;

    while(true){
        cnt = 0;

        cin >> M;
        if(!M) break;

        N = 2 * M;

        if(M == 1){
            cnt++;
            M = 2;
        }

        if(M % 2) M++;

        for(int i = M + 1; i <= N; i += 2)
            if(is_prime(i)) cnt++;
            
        cout << cnt << "\n";

    }


    return 0;
}