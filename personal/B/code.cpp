// Copyright (c) Nikita Sychev, 27.04.2017
// Licensed by MIT

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, sum = 0, psum = 0, mindiff = 1e9;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        psum = 0;
        for (int j = 0; j < n; j++)
            if (((1 << j) & i) > 0)
                psum += a[j];
        int diff = abs(sum - 2 * psum);
        if (diff < mindiff)
            mindiff = diff;
    }
    cout << mindiff << endl;
    return 0;
}
