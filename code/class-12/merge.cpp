#include <bits/stdc++.h>

using namespace std;

// To get 'good' random numbers
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int min_value = -1e6;
int max_value = 1e6;

// return a random integer in [l, r]
int random (int l, int r) {
  return uniform_int_distribution <int> (l, r)(rng);
}

vector <int> get_random_array (int n) {
  vector <int> ret(n);
  for (int& elem: ret) {
    elem = random(min_value, max_value);
  }
  return ret;
}

vector <int> merge (const vector <int>& a, const vector <int>& b) {
  const int INF = INT_MAX;
  vector <int> A = a;
  vector <int> B = b;
  int n = A.size();
  int m = B.size();
  // to simplify the implementation
  A.push_back(INF);
  B.push_back(INF);
  int it1 = 0, it2 = 0;
  vector <int> c;
  while (it1 < n or it2 < m) {
    if (A[it1] <= B[it2]) {
      c.push_back(A[it1]);
      it1++;
    } else {
      c.push_back(B[it2]);
      it2++;
    }
  }
  return c;
}

int main () {
  for (int test = 0; test < 1000; test++) {
    int n = random(1, 1000);
    int m = random(1, 1000);
    vector <int> a = get_random_array(n);
    sort(begin(a), end(a));
    vector <int> b = get_random_array(m);
    sort(begin(b), end(b));
    // naive merge
    vector <int> c;
    for (int elem: a) c.push_back(elem);
    for (int elem: b) c.push_back(elem);
    sort(begin(c), end(c));
    if (c != merge(a, b)) {
      cout << "Something is wrong!\n";
      return (-1);
    }
  }
  cout << "OK!\n";
  return (0);
}
