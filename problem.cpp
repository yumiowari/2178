#include <bits/stdc++.h>

using namespace std;

long f(long x){
    long p = 1, q = 1, i = 0, a = abs(x);

    while(a / p > 0)p *= 10;
    p /= 10;

    while(p > 0){
        i += (x / p) * q;
        x -= (x / p) * p;

        p /= 10;
        q *= 10;
    }

    return i;
}

int main(){
    long x, y;

    set<long> S;

    cin >> x;

    while(x != 0 && S.find(x) == S.end()){
        S.insert(x);

        x -= f(x);
    }

    cout << x << endl;

    return 0;
}