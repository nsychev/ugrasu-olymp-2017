// Copyright (c) Nikita Sychev, 28.04.2017
// Licensed by MIT

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int inf = 1e9;

int main() {
    int n, m, k, c, u, v, t;
    cin >> n >> m >> k >> c;
    --c;
    vector<vector<pair<int, int> > > g(n);
    vector<bool> cap(n, false);
    vector<int> d(n, inf);
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        cap[--x] = true;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> t;
        --u;
        --v;
        g[u].push_back(make_pair(v, t));
        g[v].push_back(make_pair(u, t));
    }

    set<pair<int, int> > qu;
    qu.insert(make_pair(0, c));
    d[c] = 0;
    while (qu.size() > 0) {
        int v = qu.begin()->second;
        qu.erase(qu.begin());

        for (int i = 0, len = g[v].size(); i < len; i++) {
            if (d[v] + g[v][i].second < d[g[v][i].first]) {
                d[g[v][i].first] = d[v] + g[v][i].second;
                qu.insert(make_pair(d[g[v][i].first], g[v][i].first));
            }
        }
    }

    set<pair<int, int> > ans;
    for (int i = 0; i < n; i++) {
        if (cap[i])
            ans.insert(make_pair(d[i], i + 1));
    }
    for (set<pair<int, int> >::iterator ai = ans.begin(); ai != ans.end(); ai++) {
        cout << ai->second << ' ' << ai->first << endl;
    }
    return 0;
}
