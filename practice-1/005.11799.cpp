#include <bits/stdc++.h>

using namespace std;

int solv() {
	int n, mx = 0, t;
	cin >> n;
	while (n--) {
		cin >> t;
		mx = max(mx, t);
	}
	return mx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Case " << i << ": " << solv() << '\n';
	}
}
