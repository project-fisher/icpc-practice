#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, k, c;
	cin >> t;
	while (t--) {
		cin >> n;
		c = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> k;
			c = gcd(c, abs(k - i));
		}
		cout << c << '\n';
	}
	return 0;
}
