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

int main () {
  int n = 3;
  for (int mask = 0; mask < (1 << n); mask++) {
    vector <int> subset;
    for (int bit = 0; bit < n; bit++) {
      if ((mask >> bit) & 1) {
        subset.push_back(bit + 1);
      }
    }
    print(subset);
  }
  return (0);
}
