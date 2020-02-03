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

const int N = 4e4;
vi kaprekar;

bool isKaprekar (int n) {
  string sq = to_string(n * n);
  for (int i = 0; i + 1 < sz(sq); i++) {
    int l = stoi(sq.substr(0, i + 1));
    int r = stoi(sq.substr(i + 1));
    if (0 < min(l, r) and l + r == n) return true;
  }
  return false;
}

void preprocess () {
  for (int n = 2; n <= N; n++) {
    if (isKaprekar(n)) {
      kaprekar.pb(n);
    }
  }
}


int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  preprocess(); // just 19 elements
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    int l, r;
    cin >> l >> r;
    vi ans;
    for (int elem: kaprekar) {
      if (l <= elem and elem <= r) {
        ans.pb(elem);
      }
    }
    if (t > 1) cout << '\n';
    cout << "case #" << t << '\n';
    if (ans.empty()) {
      cout << "no kaprekar numbers\n";
    } else {
      for (int elem: ans) {
        cout << elem << '\n';
      }
    }
  }
  return (0);
}
