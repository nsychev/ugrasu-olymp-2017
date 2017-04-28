// Copyright (c) Nikita Sychev, 27.04.2017
// Licensed by MIT

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y, z, w, ans = 0;
    cin >> x >> y >> z >> w;
    for (int ix = 0, cx = w / x; ix <= cx; ix++) {
        for (int iy = 0, cy = (w - ix * x) / y; iy <= cy; iy++) {
            int rem = w - ix * x - iy * y;
            if (rem % z == 0) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
