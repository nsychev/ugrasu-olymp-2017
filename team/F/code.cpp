// Copyright (c) Nikita Sychev, 2017
// Licensed by MIT

#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0, maxcnt = 0;
    for (int i = 0, len = s.length(); i < len; i++) {
        if (s[i] == '1')
            cnt = 0;
        else
            ++cnt;
        if (cnt > maxcnt)
            maxcnt = cnt;
    }
    cout << maxcnt;
}
