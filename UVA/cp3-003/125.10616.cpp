// 0.020s/1684(1)
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int memo[201][11][50];
vector<ll> data;

ll dp(int d, int m, int pos, int ofst) {
	if (m == 0) return ofst == 0;	
	if (pos == data.size()) return 0;
	if (memo[pos][m][ofst + 22] != -1) return memo[pos][m][ofst + 22];
	return memo[pos][m][ofst + 22] = dp(d, m - 1, pos + 1, (ofst + data[pos])%d) + dp(d, m, pos + 1, ofst);
}

int main() {
	int n, q;
	int T = 1;
	while (scanf("%d%d", &n, &q) && n && q) {
		printf("SET %d:\n", T++);
		data.resize(n); for (int i = 0; i < n; ++i) scanf("%lld", &data[i]);
		for (int Q = 1; Q <= q; ++Q) {
			int d, m; scanf("%d%d", &d, &m);
			memset(memo, -1, sizeof(memo));
			printf("QUERY %d: %lld\n", Q, dp(d, m, 0, 0));
		}
	}
	return 0;
}
