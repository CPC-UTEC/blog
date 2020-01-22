#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f (int n) {
  if (n == 0) return 1;
  return n * f(n - 1);
}

int main () {
  for (int n: {1, 2, 3, 4, 5, 9}) {
    printf("f(%d) = %lld\n", n, f(n));
  }
  return (0);
}
