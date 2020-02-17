#include <bits/stdc++.h>
     
using namespace std;
     
// Here is passed a reference to 'arr' in O(1)
// You CAN read from 'arr', but you CAN NOT modify it
void f1 (const vector <int>& arr) {

}
     
// Here is passed a reference to 'arr' in O(1)
// You CAN read from 'arr' and you CAN modify it
void f2 (vector <int>& arr) {
}
     
// Here is passed a copy of 'arr' in O(n)
// You CAN read from 'arr' and you CAN modify it
// BUT, you are modifying a copy of 'arr', not the 'arr' of 'main'
void f3 (vector <int> arr) {
     
}
     
int main () {
  int n = 10000;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i] = i;
  }
  f1(arr);
  f2(arr);
  f3(arr);
  return (0);
}
