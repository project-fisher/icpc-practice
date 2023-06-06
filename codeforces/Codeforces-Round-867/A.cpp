#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int n, t, b, max = 0;
		cin >> n >> t;
		int pos = -1;
		vector<int> data(n);
		for (int i = 0; i < n; cin >> data[i], i++);

		for (int i = 0; i < n; ++i) {
			cin >> b;
			if ((data[i] + i) <= t && max <= b) {
				pos = i + 1;
				max = b;
			}
		}
		cout << pos << '\n'; 
	}
	return 0;
}
