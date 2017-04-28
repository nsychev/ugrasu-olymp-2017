// Copyright (c) Nikita Sychev, 28.04.2017
// Licensed by MIT

#include <iostream>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  long long p = 1, f = 1;
  for (int i = 1; i <= k; i++) {
    p *= (n - i + 1) * (n - i + 1);
    f *= i;
  }
  cout << p / f;
  return 0;
}
