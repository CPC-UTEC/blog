#include <bits/stdc++.h>

using namespace std;

int main () {
  vector <int> arr;
  // Add a element to the end of the vector - O(1)
  arr.push_back(123);
  arr.push_back(987);
  arr.push_back(343);
  arr.push_back(134);
  arr.push_back(345);
  // Delete the last element - O(1)
  arr.pop_back();
  // Insert a element in the i-th position - O(n)
  int i = 2;
  arr.insert(begin(arr) + i, 234);
  // Delete a element in the i-th position - O(n)
  i = 1;
  arr.erase(begin(arr) + i);
  // Copy the vector - O(n)
  vector <int> arrCopy = arr;
  // We can iterate a vector in this way
  for (int arr_i: arr) {
    // do something
  }
  // We can also use 'auto'
  for (auto elem: arr) {
    cout << elem << '\n';
  }
  // We can also iterate in this way
  // arr.size() returns the number of element of the vector - O(1)
  for (int i = 0; i < arr.size(); i++) {
    // arr[i]: get the i-th element - O(1)
    cout << arr[i] << '\n';
  }
  // Delete all the elements - O(n)
  arr.clear();
  return (0);
}
