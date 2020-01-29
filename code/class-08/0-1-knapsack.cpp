#include <bits/stdc++.h>

using namespace std;

int n;
int W;
vector <int> val;
vector <int> w;
vector <int> take;
int max_sum_val = 0;
int min_sum_w = 0;
vector <int> ans_items_taken;

void backtrack (int last_taken, int sum_val, int sum_w) {
  if (sum_w <= W and (sum_val > max_sum_val or
      (sum_val == max_sum_val and sum_w < min_sum_w))) {
    max_sum_val = sum_val;
    min_sum_w = sum_w;
    ans_items_taken = take;
  }
  for (int i = last_taken + 1; i < n; i++) {
    take.push_back(i);
    backtrack(i, sum_val + val[i], sum_w + w[i]);
    take.pop_back();
  }
}

int main () {
  n = 3;
  W = 10;
  // item 1
  val.push_back(10);
  w.push_back(10);
  // item 2
  val.push_back(1);
  w.push_back(8);
  // item 3
  val.push_back(13);
  w.push_back(2);
  backtrack(-1, 0, 0);

  cout << "Take items";
  for (int item: ans_items_taken) {
    cout << ' ' << item + 1;
  }
  cout << '\n';
  return (0);
}
