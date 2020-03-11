#include <bits/stdc++.h>

using namespace std;

int main () {
  string s;
  // input
  cin >> s; // In the same way you can read a int, long long, float, ...
  // You can iterate it in this way
  for (int i = 0; i < s.size(); i++) {
    // s[i]: get the i-th element
    cout << s[i] << '\n'; // In the same way you can output a int, long long, float, ...
  }
  s[2] = 'b'; // modify the element in position 2
  // You can also print the whole string
  cout << s << '\n';
  // Yout can also iterate in this way
  for (char elem: s) {
    cout << elem;
  }
  cout << '\n'; // what happen without this line ?
  s += 'a'; // you can add append a letter or string
  cout << s.substr(2, 2) << '\n'; // what does this function do ?
  // The comparisson is like this (take care of not using just one '=' )
  if (s == "hola") cout << "ok" << '\n';
  return (0);
}
