#include <bits/stdc++.h>
using namespace std;

int rf(int n) {
	if (n <= 1) {
		return n;
	}

	return rf(n - 1) + rf(n - 2);
}

int fib(int n) {
	if (n <= 1) {
		return n;
	}

	int f;
	int f_1 = 1;
	int f_2 = 0;

	for (int i = 2; i <= n; i++) {
		f = f_1 + f_2;
		f_2 = f_1;
		f_1 = f;
	}

	return f;
}

int main() {
	int n;
	cin >> n;

	cout << fib(n) << endl;
	cout << rf(n) << endl;

	return 0;
}

