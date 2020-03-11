#include <bits/stdc++.h>

using namespace std;

struct MyStructure {
  // we can declare attributes of different types
  int var1;
  double var2;
  string var3;
  MyStructure (int var1, double var2, string _var3):
    var1(var1),
    var2(var2) { // we can initialize the variables in this way
      var3 = _var3; // ot in this way
    }
  void my_method () {
    cout << var1 << ' ' << var2 << ' ' << var3 << '\n';
  }
};

int main () {
  MyStructure structure(18, 20.7, "hello world!");
  structure.my_method(); // cal a method
  structure.var1 = 19; // access an attribute
  cout << structure.var3 << '\n';
  return (0);
}
