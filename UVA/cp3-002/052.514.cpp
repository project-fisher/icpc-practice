// 0.030s/1699
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, t, tn, bg;
	while (cin >> n && n) {
		while (cin >> t && t) {
			bool possible = 1;
			bg = t;
			bitset<10001> nn = {0};
			for (int i = 1; i < n; ++i) {
				cin >> tn;
				nn.set(t);
				if (tn > bg) bg = tn;
				else if (tn > t) possible = 0;
				else if (tn + 1 != t && possible) {
					for (int j = tn + 1; j < t; ++j) possible &= nn[j];
				}
				t = tn;
			}
			cout << (possible ? "Yes" : "No") << '\n';
		}
		cout << '\n';
	}
	return 0;
}
