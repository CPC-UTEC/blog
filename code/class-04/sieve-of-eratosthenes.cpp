#include <bits/stdc++.h>

using namespace std;

vector <bool> sieve (int n) {
  vector <bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++) {
    if (!is_prime[i]) continue;
    for (int j = 2 * i; j <= n; j += i) {
      is_prime[j] = false;
    }
  }
  return is_prime;
}

int main () {
  int n = 20;
  vector <bool> is_prime;
  is_prime = sieve(n);
  for (int i = 0; i < n; i++) {
    printf("is_prime[%2d] = %d\n", i, int(is_prime[i]));
  }
  return (0);
}
