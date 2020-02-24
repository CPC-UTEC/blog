#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> take;

const int L = 0;
const int W = 1;

int rec (int x) {
  if (x == 0) { // terminal state
    return L;
  }
  int result = L; // suppose we are in a losing state
  for (int t: take) {
    if (t <= x and rec(x - t) == L) {
      // if there is a move to a losing state
      // then we are in a winning state
      result = W;
    }
  }
  return result;
}

int main () {
  int n, m;
  while (cin >> n >> m) {
    take.resize(m);
    for (int i = 0; i < m; i++) cin >> take[i];
    if (rec(n) == W) cout << "Stan wins" << '\n';
    else cout << "Ollie wins" << '\n';
  }
  return (0);
}
