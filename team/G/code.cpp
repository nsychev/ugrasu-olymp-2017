// Copyright (c) Arslan Aknazarov, 28.04.2017
// Licensed by MIT

#include <iostream>
#include <vector>
using namespace std;

long long gcd(long long a, long long b){
    while(b > 0){
        a = a % b;
        swap(a, b);
    }
    return a;
}


int main()
{
    long long n, m;
    cin >> n >> m;
    long long g = (n * m) / gcd(n, m);
    cout << g / m;
    return 0;
}
