#include <bits/stdc++.h>

using namespace std;

int solution1 (int n) {
  int cnt = 0;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      for (int z = 1; z <= n; z++) {
        if (x * x + y * y == z * z) {
          cnt++;
        }
      }
    }
  }
  return cnt;
}

int solution2 (int n) {
  vector <bool> is_sq(n * n + 1, false);
  for (int z = 1; z <= n; z++) {
    is_sq[z * z] = true;
  }
  int cnt = 0;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      if (x * x + y * y <= n * n and is_sq[x * x + y * y]) {
        cnt++;
      }
    }
  }
  return cnt;
}

int solution3 (int n) {
  int cnt = 0;
  for (int a = 1; a * a < n; a++) {
    for (int b = 1; b < a; b++) {
      if (__gcd(a, b) != 1) continue;
      if (a % 2 and b % 2) continue;
      int x = a * a - b * b;
      int y = 2 * a * b;
      int z = a * a + b * b;
      int add = min({n / x, n / y, n / z});
      cnt += 2 * add;
    }
  }
  return cnt;
}

int main () {
  int n = 1000;
  cout << "Solution 1: " << solution1(n) << '\n';
  cout << "Solution 2: " << solution2(n) << '\n';
  cout << "Solution 3: " << solution3(n) << '\n';
  return (0);
}
