// Copyright (c) Nikita Sychev, 28.04.2017
// Licensed by MIT

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int left = 0;
    long long sum = 0, maxsum = 0;
    for (int right = 0; right < n; ++right) {
        sum += a[right];
        while (right - left > 1 && a[left] + a[left + 1] < a[right]) {
            sum -= a[left];
            ++left;
        }
        if (sum > maxsum)
            maxsum = sum;
    }
    cout << maxsum;
    return 0;
}
