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

    int M, N;

    cin >> M >> N;

    if(M < 3){
        cout << "2\n";
        M = 3;
    }

    if(!(M % 2)) M++;

    for(int i = M; i <= N; i += 2)
        if(is_prime(i)) cout << i << "\n";

    return 0;
}