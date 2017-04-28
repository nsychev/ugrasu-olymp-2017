// Copyright (c) Nikita Sychev, 27.04.2017
// Licensed by MIT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int dir = 0;
    int pos[2] = {0, n - 1};
    for (int i = 0; i < n; i++) {
        b[pos[dir]] = a[i];
        pos[dir] += 1 - dir * 2;
        dir = 1 - dir;
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    return 0;
}
