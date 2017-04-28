#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int start = -1, finish = -1;
char c;
vector<bool> isfree;
vector<int> d;

int diffs[8][2] = {
  {-2, -1},
  {-2, 1},
  {2, -1},
  {2, 1},
  {-1, -2},
  {-1, 2},
  {1, -2},
  {1, 2}
};

int to(int id, int did) {
    int x = id / n + diffs[did][0],
        y = id % n + diffs[did][1];

    if (x < 0 || x >= n)
        return -1;
    if (y < 0 || y >= n)
        return -1;

    int nid = x * n + y;

    if (!isfree[nid])
        return -1;
    if (d[nid] >= 0)
        return -1;

    return nid;
}

int main() {
    cin >> n;
    isfree.assign(n * n, true);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == '#')
                isfree[i * n + j] = false;
            else if (c == '@')
                if (start == -1)
                    start = i * n + j;
                else
                    finish = i * n + j;
        }
    }

    queue<int> bfs;
    d.assign(n * n, -1);
    bfs.push(start);
    d[start] = 0;

    while (!bfs.empty()) {
        int v = bfs.front();
        if (v == finish) {
            cout << d[v];
            return 0;
        }
        bfs.pop();

        for (int did = 0; did < 8; did++) {
            int where = to(v, did);
            if (where >= 0) {
                d[where] = d[v] + 1;
                bfs.push(where);
            }
        }
    }

    cout << -1;

    return 0;
}
