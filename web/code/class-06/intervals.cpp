#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int>> solution1 (const vector <int>& arr) {
  int n = arr.size();
  vector <bool> vis(n, false);
  vector <pair <int, int>> ret;
  for (int l = 0; l < n; l++) {
    if (vis[l]) continue;
    int L = l;
    int R = l;
    for (int r = l; r < n and arr[l] == arr[r]; r++) {
      vis[r] = true;
      R = r;
    }
    ret.push_back({1 + L, 1 + R});
  }
  return ret;  
}

vector <pair <int, int>> solution2 (const vector <int>& arr) {
  int n = arr.size();
  vector <pair <int, int>> ret;
  int l = 0;
  while (l < n) {
    int r = l;
    while (r + 1 < n and arr[l] == arr[r + 1]) r++;
    ret.push_back({1 + l, 1 + r});
    l = r + 1;
  }
  return ret;  
}


int main () {
  vector <int> arr = {1, 1, 1, 2, 2, 3, 3};
  vector <pair <int, int>> ret1 = solution1 (arr);
  vector <pair <int, int>> ret2 = solution2 (arr);
  assert (ret1 == ret2);
  for (auto pp: ret1) {
    cout << pp.first << ' ' << pp.second << '\n';
  }
  return (0);
}
