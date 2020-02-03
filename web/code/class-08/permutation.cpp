#include <bits/stdc++.h>

using namespace std;

int n;
vector <bool> used;
vector <int> permutation;

void print (const vector <int>& p) {
  for (int elem: p) {
    cout << elem << ' ';
  }
  cout << '\n';
}

void backtrack () {
  if (permutation.size() == n) {
    print(permutation);
    return;
  }
  for (int p_i = 1; p_i <= n; p_i++) {
    if (!used[p_i]) {
      used[p_i] = true;
      permutation.push_back(p_i);
      backtrack();
      used[p_i] = false;
      permutation.pop_back();
    }
  }
}

int main () {
  n = 3;
  used.resize(n + 1, false);
  backtrack();
  return (0);
}
