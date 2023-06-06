// 0.000s/1538
#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n;
	while (scanf("%d %d", &m, &n) > 0) {
		map<int, map<int, int>> g;
		for (int i = 1; i <= m; ++i) {
			int r; scanf("%d", &r); if (!r) continue;
			vector<int> poss(r);
			for (int j = 0; j < r; ++j) scanf("%d", &poss[j]);
			for (int j = 0; j < r; ++j) {
				int t; scanf("%d", &t);
				g[poss[j]][i] = t;
			}
		}
		printf("%d %d\n", n, m);
		int prev = 0;
		for (const auto &i : g) {
			for (int j = prev + 1; j < i.first; ++j) printf("0\n\n");
			printf("%d", i.second.size());
			for (const auto &j : i.second) printf(" %d", j.first); printf("\n");
			bool first = 0;
			for (const auto &j : i.second) {
				if (first) printf(" ");
				else first = 1;
				printf("%d", j.second);
			} printf("\n");
			prev = i.first;
		}
		for (int i = prev + 1; i <= n; ++i) printf("0\n\n");
	}
	return 0;
}
