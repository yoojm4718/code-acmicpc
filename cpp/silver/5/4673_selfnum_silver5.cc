#include <bits/stdc++.h>

using namespace std;

bool has_kaprekar(int n){
    int temp, num;

    for(int i = n - 1; i > 0; i--){
        num = i;
        temp = i;
        while(temp){
            num += temp % 10;
            temp /= 10;
        }
        if(num == n) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for(int i = 1; i < 10000; i++)
        if(!has_kaprekar(i)) cout << i << "\n";

    return 0;
}