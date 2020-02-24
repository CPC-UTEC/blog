#include <bits/stdc++.h>

using namespace std;

int main () {
  int n;
  while (cin >> n, n != 0) {
    int nim_sum = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      nim_sum ^= x;
    }
    puts(nim_sum == 0 ? "No" : "Yes");
  }
  return (0);
}
