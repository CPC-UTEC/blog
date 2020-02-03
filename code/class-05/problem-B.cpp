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
  int n;
  cin >> n;
  vector <pair <pii, int>> arr(n + 1);
  arr[0] = mp(pii(0, 0), 0);
  for (int i = 1; i <= n; i++) {
    arr[i].second = i;
    cin >> arr[i].first.first >> arr[i].first.second;
  }
  sort(all(arr));
  vi ans;
  for (auto fix: arr) {
    if (fix.second == 0) continue;
    int prev = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (arr[i] == fix) continue;
      ok &= (arr[prev].first.second <= arr[i].first.first);
      prev = i;
    }
    if (ok) ans.pb(fix.second);
  }
  sort(all(ans));
  cout << sz(ans) << '\n';
  for (int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i == sz(ans) - 1];
  return (0);
}
