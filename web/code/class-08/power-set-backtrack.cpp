#include <bits/stdc++.h>

using namespace std;

void print (const vector <int>& arr) {
  cout << "{";
  bool first = true;
  for (int elem: arr) {
    if (!first) {
      cout << ", ";
    }
    cout << elem;
    first = false;
  }
  cout << "}\n";
}

void backtrack (vector <int>& arr, const int n) {
  print(arr);
  int ax = 0;
  if (!arr.empty()) {
    ax = arr.back();
  }
  for (int ay = ax + 1; ay <= n; ay++) {
    // add ay
    arr.push_back(ay);
    backtrack(arr, n);
    // delete ay
    arr.pop_back();
  }
}

int main () {
  int n = 3;
  vector <int> subset;
  backtrack(subset, n);
}
