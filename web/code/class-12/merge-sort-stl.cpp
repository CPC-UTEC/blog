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

vector <int> merge_sort (const vector <int>& a) {
  if (a.size() <= 1) return a;
  int m = a.size() / 2;
  vector <int> left(begin(a), begin(a) + m);
  vector <int> right(begin(a) + m, end(a));
  vector <int> x = merge_sort(left);
  vector <int> y = merge_sort(right);
  vector <int> ret;
  std::merge(begin(x), end(x),
             begin(y), end(y),
             std::back_inserter(ret));
  return ret;
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
