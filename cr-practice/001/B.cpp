#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, q, a, l;
	cin >> n >> k >> q;
	vector<int> data(k);
	for (int i = 0; i < k; ++i) cin >> data[i];
	sort(data.begin(), data.end());
	for (int i = 0; i < q; ++i) {
		cin >> l;
		--l;
		if (data[l] < n && (l + 1 == k || data[l + 1] != data[l] + 1)) ++data[l];
	}
	cout << data[0];
	for (int i = 1; i < k; ++i) cout << ' ' << data[i];
	cout << '\n';
	return 0;
}
