// 0.000s/1092
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, v, m;
	while (cin >> n) {
		m = 1 << n;
		int vals[m];
		for (int i = 0; i < m; ++i) vals[i] = 0;
		for (int i = 0; i < m; ++i) {
			cin >> v;
			for (int j = 0; j < n; ++j) vals[i^(1 << j)] += v;
		}
		int mx = 0;
		for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) mx = max(mx, vals[i] + vals[i^(1 << j)]);
		cout << mx << '\n';
	}
	return 0;
}
