#include <bits/stdc++.h>

using namespace std;

int main () {
  set <int> S;
  // Insert a element - O(log n)
  S.insert(3);
  S.insert(4);
  S.insert(-100);
  S.insert(-345);
  // The elements are stored in ascending order
  for (auto x: S) {
    cout << x << endl;
  }
  // Check if a element is in the set - O(log n)
  if (S.count(4) > 0) {
    cout << "4 is in S\n";
  }
  // You can also check that using the method find
  if (S.find(4) != end(S)) {
    cout << "4 is in S" << endl;
  }
  // Delete a elemento - O(log n)
  S.erase(4);
  // You can also delete in this way
  S.erase(S.find(-100));
  // If we store the iterator - O(log n)
  // auto it = S.find(val) - O(log n)
  // Then we can erase the element - O(1)
  // S.erase(it)
  return (0);
}
