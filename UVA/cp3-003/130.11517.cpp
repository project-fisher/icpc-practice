// 0.070s/2429(3)
#include <bits/stdc++.h>

using namespace std;

int c[101];
int k, m;

pair<int, int> memo[101][20003];
bitset<101> memob[20003];

pair<int, int> dp(int i, int v) {
	if (i == k && v < m) return {INT_MAX - 1, INT_MAX - 1};
	else if (v >= m) return {v - m, 0};
	if (memob[v][i]) return memo[i][v];
	auto a = dp(i + 1, v);
	auto b = dp(i + 1, v + c[i]);
	++b.second;
	memob[v].set(i);
	return memo[i][v] = a < b ? a : b;
}

int main() {
	int n; scanf("%d", &n);
	long best[20002];
	best[0] = 0;
	while (n--) {
		for (int i = 0; i < 20002; ++i) memob[i].reset();
		scanf("%d", &m);
		scanf("%d", &k);
		for (int i = 0; i < k; ++i) scanf("%d", &c[i]);
		auto r = dp(0, 0);
		printf("%d %d\n", m + r.first, r.second);
	}
	return 0;
}
		
