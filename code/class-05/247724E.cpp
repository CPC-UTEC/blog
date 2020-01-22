#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll m = 1e9 + 7;

ll add (ll a, ll b) { return ((a) % m + (b % m)) % m; }
ll sub (ll a, ll b) { return (((a) % m - (b % m)) + m) % m; }
ll mul (ll a, ll b) { return ((a) % m * (b % m)) % m; }

ll binpow (ll a, ll b) {
  if (b == 0) return 1;
  a %= m;
  ll res = binpow(a, b / 2);
  res = mul(res, res);
  if (b % 2 == 1) res = mul(a, res);
  return res;
}

ll inverse (ll a) { return binpow(a, m - 2); }

int main () {
  ll a, k;
  cin >> a >> k;
  if (sub(a, 1) == 0) {
    cout << add(k, 1) << '\n';
  } else {
    cout << mul(sub(binpow(a, k + 1), 1), inverse(a - 1)) << '\n';
  }
  return (0);
}
