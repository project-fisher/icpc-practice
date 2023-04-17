#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	unsigned long n, a;
	while (cin >> n && n) {
		a = 0;
		bool parity = 0;
		for (unsigned long pos = 1; pos <= n; a += (parity ? n&pos : 0), pos <<= 1) parity ^= (bool)(n&pos);
		cout << a << ' ' << n - a << '\n';
	}
	return 0;
}
