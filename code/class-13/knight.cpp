#include <bits/stdc++.h>

using namespace std;

int n;
vector <string> board;
vector <vector <int>> memo;

const int UNVISITED = -1;
const vector <int> dr = {1, -1, -2, -2};
const vector <int> dc = {-2, -2, -1, 1};

int grundy (int r, int c) {
  if (memo[r][c] != UNVISITED) {
    return memo[r][c];
  }
  set <int> values;
  for (int d = 0; d < dr.size(); d++) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (0 <= min(nr, nc) and max(nr, nc) < n) {
      values.insert(grundy(nr, nc));
    }
  }
  int mex = 0;
  while (values.count(mex)) mex++;
  return memo[r][c] = mex;
}

int main () {
  /* Input example
  8
  ........
  ..K..K..
  .......K
  ........
  ...K....
  ........
  ....K...
  ..K.....
  */
  cin >> n;
  board.resize(n);
  memo = vector <vector <int>> (n, vector <int> (n, UNVISITED));
  for (int i = 0; i < n; i++) cin >> board[i];
  vector <int> values;
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      if (board[r][c] == 'K') {
        values.push_back(grundy(r, c));
      }
    }
  }
  int mex = 0;
  for (int elem: values) {
    mex ^= elem;
  }
  if (mex == 0) {
    cout << "The first player is in a losing state" << '\n';
  } else {
    cout << "The first player is in a winning state" << '\n';
  }
  return (0);
}
