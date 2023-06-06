#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> data(n);
		int r = 0;
		for (int i = n; i > 1; --i) {
			data[n - i] = (n/i)*i;
			r += n - (n/i)*i;
			r %= n;
		}
		data[n - 1] = n + r;
		cout << data[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			cout << ' ' << data[i];
		}
		cout << '\n';
	}
	return 0;
}
