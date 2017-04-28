// Copyright (c) Nikita Sychev, 28.04.2017
// Licensed by MIT

#include <iostream>

using namespace std;

int main() {
    int d, n;
    cin >> d >> n;

    int _a = 1, _b = 0, a = 0, b = 1, sa, sb;

    for (int i = 3; i <= d; i++) {
        sa = a + _a, sb = b + _b;
        _a = a, _b = b;
        a = sa, b = sb;
    }

    for (int x = 1; x <= n; ++x) {
        if ((n - a * x) % b > 0)
            continue;
        int y = (n - a * x) / b;
        if (y >= 0 && y < x) {
            cout << x << ' ' << y << endl;
            return 0;
        }
    }
}
