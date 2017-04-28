// Copyright (c) Nikita Sychev, 27.04.2017
// Licensed by MIT

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int div = 2;
    while (div <= sqrtl(n) + 1) {
        while (n % div == 0) {
            cout << div << endl;
            n /= div;
        }
        ++div;
    }
    if (n > 1)
        cout << n << endl;
    return 0;
}
