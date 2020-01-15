#include <bits/stdc++.h>

using namespace std;

vector <int> nDivisors (int n) {
  vector <int> n_div(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      n_div[j] += 1;
    }
  }
  return n_div;
}

int main () {
  int n = 20;
  vector <int> n_div = nDivisors(n);
  for (int i = 1; i <= n; i++) {
    printf("n_div[%2d] = %d\n", i, n_div[i]);
  }
  return (0);
}
