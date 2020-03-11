#include <bits/stdc++.h>

using namespace std;

/**
 * is_prime[i] = indicates whether or not 'i' is prime
 */
vector <bool> sieve (int n) {
  vector <bool> is_prime(n, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < n; i++) {
    if (!is_prime[i]) continue;
    for (int j = i + i; j < n; j += i) {
      is_prime[j] = false;
    }
  }
  return is_prime;
}

int main () {
  for (int n = 1000000; n < 2000000; n += 100000) {
    clock_t start = clock();
    vector <bool> is_prime = sieve(n);
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time(" << n << ") = " << fixed << setprecision(6) << duration << " seconds\n";
  }
  return (0);
}
