#include <bits/stdc++.h>

using namespace std;

// Returns true if p is in A in O(n)
bool brute_force (const vector <int>& A, int p) {
  for (int elem: A) {
    if (elem == p) return true;
  }
  return false;
}

// Returns true if p is in A in O(log n)
bool divide_and_conquer (const vector <int>& A, int p) {
  int l = 0, r = A.size() - 1;
  while (l != r) {
    int m = (l + r) >> 1; // = (l + r) / 2
    bool f_p = (p <= A[m]);
    if (f_p) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  int z = l;
  return (A[z] == p);
}

int main () {
  // To get 'good' random numbers
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  // Create A with n random values
  int n = 1000;
  int min_value = -1e6;
  int max_value = 1e6;
  vector <int> A(n);
  for (int& elem: A) {
    elem = uniform_int_distribution <int> (min_value, max_value)(rng);
  }
  sort(begin(A), end(A));
  // Check q queries
  int q = 1000;
  for (int i = 0; i < q; i++) {
    int p = uniform_int_distribution <int> (min_value, max_value)(rng);
    bool ret1 = brute_force(A, p);
    bool ret2 = divide_and_conquer(A, p);
    if (ret1 != ret2) {
      cout << "Something is wrong!\n";
      return (-1);
    }
  }
  cout << "OK!\n";
  return (0);
}
