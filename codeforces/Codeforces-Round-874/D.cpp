#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; ++i) cin >> p[i];
		if (n == 1) cout << "1\n";
		else {
			auto k = max_element(p.begin(), p.end());
			if (*k == p[0]) k = find(p.begin(), p.end(), *k - 1);
			int l = distance(p.begin(), k), r;
			if (*k != p.back()) --l;
			r = l - 1;
			while (r > 0 && p[0] < p[r]) --r;
			++r;
			cout << *k;
			if (*k != p.back()) {
				for (int i = l + 2; i < n; ++i) cout << ' ' << p[i];
			}
			for (int i = l - (*k == p.back()); i >= r; --i) cout << ' ' << p[i];
			for (int i = 0; i < r; ++i) cout << ' ' << p[i];
			cout << '\n';
		}
	}
	return 0;
}
