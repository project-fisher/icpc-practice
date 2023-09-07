#include <bits/stdc++.h>

#define ll long long

using namespace std;

const ll MIN = LLONG_MIN;

int n, w[101];

ll v[101], memo[101][100001] = {0};

ll dp(int pos, int W) {
	if (W < 0) return MIN;
	if (pos == n) return 0;
	if (memo[pos][W]) return memo[pos][W];
	return memo[pos][W] = max(dp(pos + 1, W), dp(pos + 1, W - w[pos]) + v[pos]);
}

int main() {
	int W; scanf("%d%d", &n, &W);
	for (int i = 0; i < n; ++i) scanf("%d%lld", &w[i], &v[i]);
	printf("%lld\n", dp(0, W));
	return 0;
}

