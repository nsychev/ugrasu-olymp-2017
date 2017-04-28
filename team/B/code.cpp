// Copyright (c) Arslan Aknazarov, 28.04.2017
// Licensed by MIT

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long d = 0;
    vector<long long> ans(10, 0);

    for (long long i = 2; i < 10; i++){
        long long now = n;
        while(now % i == k){
            ans[i]++;
            now /= i;
        }
        if (ans[i] > ans[d])
            d = i;
    }
    if (d != 0)
        cout << d << ' ' << ans[d];
    else{
        cout << 0;
    }
    return 0;
}
