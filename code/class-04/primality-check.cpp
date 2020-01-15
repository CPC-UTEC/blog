#include <bits/stdc++.h>

using namespace std;

bool isPrime1 (int n) {
  int n_div = 0;
  for (int d = 1; d <= n; d++) {
    if (n % d == 0) n_div++;
  }
  return (n_div == 2);
}

bool isPrime2 (int n) {
  int n_div = 0;
  for (int d = 1; d * d <= n; d++) {
    if (n % d == 0) {
      n_div++;
      if (n / d != d) n_div++;
    }
  }
  return (n_div == 2);
}

int main () {
  for (int n: {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}) {
    printf("isPrime1(%2d) = %2d ------ isPrime2(%2d) = %2d\n", n, isPrime2(n), n, isPrime2(n));
  }
  return (0);
}
