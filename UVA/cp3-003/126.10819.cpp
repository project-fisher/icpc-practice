// 0.400s/2124(1)
#include <bits/stdc++.h>

using namespace std;

int m, n, v[101], w[101], memo[101][2][10001];

int dp(int i, bool e, int x) {
	if (!e && m - x > 2000) {
		x += 200;
		e = 1;
	}
	if (x < 0 && e) return INT_MIN; 
	if (i == n) return x < 0 ? INT_MIN : 0;
	if (memo[i][e][x] != -1) return memo[i][e][x];
	return memo[i][e][x] = max(dp(i + 1, e, x - w[i]) + v[i], dp(i + 1, e, x));
}

int main() {
	while (scanf("%d%d", &m, &n) != -1) {
		for (int i = 0; i < n; ++i) scanf("%d%d", &w[i], &v[i]);
		memset(memo, -1, sizeof(memo));
		printf("%d\n", dp(0, 0, m));
	}
	return 0;
}
		
