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

    int T, n, part;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> n;
        for(part = n / 2; part > 0; part--)
            if(is_prime(part))
                if(is_prime(n - part)){
                    cout << part << " " << n - part << "\n";
                    break;
                }
        
    }

    return 0;
}