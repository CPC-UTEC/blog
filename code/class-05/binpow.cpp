#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll m = 1e9 + 7;

ll binpow (ll a, ll b) {
  if (b == 0) return 1;
  a %= m;
  ll res = binpow(a, b / 2);
  res = (res * res) % m;
  if (b % 2 == 1) res = (a * res) % m;
  return res;
}

int main () {
  ll a = 123435, b = 3354;
  ll ret = 1;
  for (int i = 1; i <= b; i++) {
    ret = (ret * a) % m;
  }
  cout << ret << ' ' << binpow(a, b) << '\n';
  return (0);
}
