// Copyright (c) Nikita Sychev, 27.04.2017
// Licensed by MIT

#include <iostream>
#include <vector>

using namespace std;

vector<int> color;
vector<vector<int> > g;

bool dfs(int v) {
    if (color[v] == 2)
        return false;
    if (color[v] == 1)
        return true;
    color[v] = 1;
    for (int i = 0, len = g[v].size(); i < len; i++) {
        if (dfs(g[v][i]))
            return true;
    }
    color[v] = 2;
    return false;
}

int main() {
    int n, m, a, b;
    cin >> n >> m;
    n = 5000;
    color.assign(n, 0);
    g.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
    }
    for (int i = 0; i < n; i++) {
        if (dfs(i)) {
            cout << -1;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
