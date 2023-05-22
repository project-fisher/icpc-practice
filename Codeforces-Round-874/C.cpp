#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<long> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		bool parity = a[0]&1, possible = 1;
		for (int i = 1; i < n && possible; ++i) possible = parity || !(a[i]&1);
		cout << (possible ? "yes" : "no") << '\n';
	}
	return 0;
}
