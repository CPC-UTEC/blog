#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> take;
vector <int> memo;

const int UNVISITED = -1;

int grundy (int x) {
  if (x == 0) { // terminal state
    return 0; // mex 0
  }
  if (memo[x] != UNVISITED) { // we have already compute it
    return memo[x];
  }
  set <int> values;
  for (int t: take) {
    if (t <= x) {
      values.insert(grundy(x - t));
    }
  }
  int mex = 0;
  while (values.count(mex)) mex++;
  return memo[x] = mex;
}

int main () {
  while (cin >> n >> m) {
    take.resize(m);
    memo.resize(n + 1, UNVISITED);
    for (int i = 0; i < m; i++) cin >> take[i];
    if (grundy(n) != 0) cout << "Stan wins" << '\n';
    else cout << "Ollie wins" << '\n';
    take.clear();
    memo.clear();
  }
  return (0);
}
