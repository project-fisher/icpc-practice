// 0.000s/740
#include <bits/stdc++.h>

using namespace std;

long coin_best(vector<pair<int, int>> &c, int S) {
	long best[S + 1][S + 1];
	long s2 = S*S;
	best[0][0] = 0;
	for (int i = 0; i <= S; ++i) for (int j = i == 0; j <= S && i*i + j*j <= s2; ++j) {
		long mn = LONG_MAX - 1;
		for (auto &k : c) if (i >= k.first && j >= k.second) mn = min(mn, 1 + best[i - k.first][j - k.second]);
		best[i][j] = mn;
	}
	long mn = LONG_MAX - 1;
	for (int i = 0; i <= S; ++i) for (int j = 0; j <= S && i*i + j*j <= s2; ++j) if (i*i + j*j == s2) mn = min(mn, best[i][j]);
	return mn;
}

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int m, S; scanf("%d%d", &m, &S);
		vector<pair<int, int>> c(m); for (int i = 0; i < m; ++i) scanf("%d%d", &c[i].first, &c[i].second);
		long ans = coin_best(c, S);
		if (ans == LONG_MAX - 1) puts("not possible");
		else printf("%ld\n", ans);
	}
	return 0;
}

