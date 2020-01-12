#include <bits/stdc++.h>

using namespace std;

int main () {
  map <string, int> my_map;
  // Insert a element - O(log n)
  my_map["hola"] = 1;
  my_map["mundo"] = 5;
  // The elements are stored in ascending order
  for (auto x: my_map) {
    cout << x.first << ' ' << x.second << endl;
  }
  // Check if a element is in the map - O(log n)
  if (my_map.count("hola") > 0) {
    cout << "4 is in my_map\n";
  }
  // You can also check that using the method find
  if (my_map.find("hola") != end(my_map)) {
    cout << "4 is in my_map" << endl;
  }
  my_map["hola"] = 10;
  for (auto x: my_map) {
    cout << x.first << ' ' << x.second << '\n';
  }
  // Delete a elemento - O(log n)
  my_map.erase("hola");
  // You can also delete in this way
  my_map.erase(my_map.find("mundo"));
  // If we store the iterator - O(log n)
  // auto it = my_map.find(val) - O(log n)
  // Then we can erase the element - O(1)
  // my_map.erase(it)
  return (0);
}
