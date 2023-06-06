#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long n, k; cin >> n >> k;
		vector<pair<long, long>> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a.begin(), a.end());
		vector<long> b(n);
		for (int i = 0; i < n; ++i) cin >> b[i];
		sort(b.begin(), b.end());
		vector<long> r(n);
		for (int i = 0; i < n; ++i) r[a[i].second] = b[i];
		cout << r[0];
		for (int i = 1; i < n; ++i) cout << ' ' << r[i];
		cout << '\n';
	}
	return 0;
}
