// 0.010s/1655
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	bitset<1000001> data;
	while (cin >> n >> m && n|m) {
		bool ncol = 1;
		long int se, ee, rep;
		data.reset();
		while (n--) {
			cin >> se >> ee;
			for (int i = se; ncol && i < ee; data.set(i), ++i) ncol = !data[i];
		}
		while (m--) {
			cin >> se >> ee >> rep;
			while (ncol && se < 1000001) {
				for (int i = se; ncol && i < ee && i < 1000001; data.set(i), ++i) ncol = !data[i];
				se += rep;
				ee += rep;
			}
		}
		cout << (!ncol ? "CONFLICT\n" : "NO CONFLICT\n");
	}
	return 0;
}
