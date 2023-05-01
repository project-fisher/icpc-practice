#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin >> c;
	for (int i = 0; i < c; ++i) {
		if (i) cout << '\n';
		int n, m;
		unsigned long t, total = 0, totalm;
		queue<array<int, 2>> cars[2];
		cin >> n >> t >> m;
		long data[m];
		for (int j = 0; j < m; ++j) {
			int tm;
			string side;
			cin >> tm >> side;
			cars[side == "right"].push({tm, j});
		}
		bool side = 0;
		while (!(cars[0].empty() && cars[1].empty())) {
			// the next few lines are pure evil...
			if (!cars[side].empty()) {
				if (cars[side].front()[0] > total) {
					if (!cars[!side].empty() && cars[side].front()[0] > cars[!side].front()[0]) {
						if (cars[!side].front()[0] > total) total = cars[!side].front()[0];
					} else total = cars[side].front()[0];
				}
			} else if (cars[!side].front()[0] > total) total = cars[!side].front()[0];
			totalm = total + t;
			for (int j = 0; !cars[side].empty() && cars[side].front()[0] <= total && j < n; ++j) {
				data[cars[side].front()[1]] = totalm;
				cars[side].pop();
			}
			total = totalm;
			side = !side;
		}
		for (auto &j : data) cout << j << '\n';
	}
	return 0;
}
