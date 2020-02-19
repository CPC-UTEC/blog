#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
  int n, k;
  cin >> n >> k;
  vector <int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(begin(a), end(a));
  int y = n / 2;
  ll median = a[y];
  ll l = median, r = median + k;
  while (l != r) {
    ll m = (l + r + 1) / 2;
    ll n_operations = 0;
    for (int i = y; i < n; i++) {
      if (a[i] < m) {
        n_operations += m - a[i];
      }
    }
    if (l < 0) break;
    if (n_operations <= k) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  int z = l;
  cout << z << '\n';
  return (0);
}
