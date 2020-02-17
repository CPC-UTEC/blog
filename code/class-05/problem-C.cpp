#include <bits/stdc++.h>
 
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <ll> vll;
 
int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  const ll MOD = 10000;
  int n, u, q;
  cin >> n >> u >> q;
  vector <pii> update(u);
  for (int i = 0; i < u; i++) cin >> update[i].first >> update[i].second;
  auto get = [&] (ll x) {
    return x * (x + 1) / 2;
  };
  while (q--) {
    int l, r;
    cin >> l >> r;
    ll ans = 0;
    for (auto pp: update) {
      int L = max(pp.first, l);
      int R = min(pp.second, r);
      if (L <= R) {
        ll x = L - pp.first + 1;
        ll y = R - pp.first + 1;
        ans += get(y) - get(x - 1);
        ans %= MOD;
      }
    }
    cout << ans << '\n';
  }
  return (0);
}
