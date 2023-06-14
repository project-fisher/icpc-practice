// 1.560s/1207(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, y;
	while (scanf("%d%d", &x, &y) == 2 && x && y) {
		vector<vector<int>> a(x, vector<int>(y));
		for (int i = 0; i < x; ++i) for (int j = 0; j < y; ++j) scanf("%d", &a[i][j]);
		vector<vector<int>> diag;
		for (int i = x - 1; i >= 0; --i) {
			diag.push_back({});
			for (int pos_x = i, pos_y = 0; pos_x < x && pos_y < y; ++pos_x, ++pos_y) diag.back().push_back(a[pos_x][pos_y]);
		}
		for (int i = 1; i < y; ++i) {
			diag.push_back({});
			for (int pos_x = 0, pos_y = i; pos_x < x && pos_y < y; ++pos_x, ++pos_y) diag.back().push_back(a[pos_x][pos_y]);
		}
		int q; scanf("%d", &q);
		while (q--) {
			int w, z; scanf("%d%d", &w, &z);
			int mx = 0;
			for (auto &i : diag) {
				auto it_1 = lower_bound(i.begin(), i.end(), w);
				auto it_2 = upper_bound(i.begin(), i.end(), z);
				if (it_1 == i.end() || (it_2 == i.begin() && *it_2 < z)) continue;
				int dist = distance(it_1, it_2);
				mx = max(mx, dist);
			}
			printf("%d\n", mx);
		}
		printf("-\n");
	}
	return 0;
}

