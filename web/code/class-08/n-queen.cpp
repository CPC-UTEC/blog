#include <bits/stdc++.h>

using namespace std;

int n;
vector <pair <int, int>> queen;
vector <pair <int, int>> solution;

bool valid (int r, int c) {
  for (auto pp: queen) {
    // if same row or same column or same diagonal
    if ((pp.first == r) or
        (pp.second == c) or
        (abs(r - pp.first) == abs(c - pp.second))) {
      return false;
    }
  }
  return true;
}

void backtrack (int r) {
  if (r == n) {
    solution = queen;
    return;
  }
  if (!solution.empty()) {
    return;
  }
  for (int c = 0; c < n; c++) {
    if (valid(r, c)) {
      queen.push_back({r, c});
      backtrack(r + 1);
      queen.pop_back();
    }
  }
}

int main () {
  cin >> n;
  backtrack(0);
  if (solution.empty()) {
    cout << "NO\n";
    return (0);
  }
  vector <vector <int>> board(n, vector <int> (n, 0));
  for (auto pp: solution) {
    board[pp.first][pp.second] = 1;
  }
  cout << "YES\n";
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cout << board[r][c] << " \n"[c == n - 1];
    }
  }
  return (0);
}
