#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> take;
vector <int> memo;

const int L = 0;
const int W = 1;
const int UNVISITED = 2;

int rec (int x) {
  if (x == 0) { // terminal state
    return L;
  }
  if (memo[x] != UNVISITED) { // we have already compute it
    return memo[x];
  }
  int result = L; // suppose we are in a losing state
  for (int t: take) {
    if (t <= x and rec(x - t) == L) {
      // if there is a move to a losing state
      // then we are in a winning state
      result = W;
    }
  }
  return memo[x] = result;
}

int main () {
  while (cin >> n >> m) {
    take.resize(m);
    memo.resize(n + 1, UNVISITED);
    for (int i = 0; i < m; i++) cin >> take[i];
    if (rec(n) == W) cout << "Stan wins" << '\n';
    else cout << "Ollie wins" << '\n';
    take.clear();
    memo.clear();
  }
  return (0);
}
