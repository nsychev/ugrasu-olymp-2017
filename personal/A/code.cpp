// Copyright (c) Nikita Sychev, 27.04.2017
// Licensed by MIT

#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0, len = s.length(); i < len; ++i) {
        sum += int(s[i]) - 48;
    }
    if (sum % 3 == 0)
        cout << 2;
    else
        cout << 1 << endl << sum % 3;
    return 0;
}
