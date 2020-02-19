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

vector <int> merge_sort (const vector <int>& a) {
  if (a.size() <= 1) return a;
  int m = a.size() / 2;
  vector <int> left;
  for (int i = 0; i < m; i++) left.push_back(a[i]);
  vector <int> right;
  for (int i = m; i < a.size(); i++) right.push_back(a[i]);
  vector <int> x = merge_sort(left);
  vector <int> y = merge_sort(right);
  return merge(x, y);
};

int main () {
  for (int test = 0; test < 1000; test++) {
    int n = random(1, 1000);
    vector <int> a = get_random_array(n);
    vector <int> sorted_a = a;
    sort(begin(sorted_a), end(sorted_a));
    if (sorted_a != merge_sort(a)) {
      cout << "Something is wrong!\n";
      return (-1);
    }
  }
  cout << "OK!\n";
  return (0);
}
