#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, v[101];

ll w[101];

map<ll, int> memo[101];

int dp(int pos, ll W) {
	if (W < 0) return INT_MIN;
	if (pos == n) return 0;
	if (memo[pos].count(W)) return memo[pos][W];
	return memo[pos][W] = max(dp(pos + 1, W), dp(pos + 1, W - w[pos]) + v[pos]);
}

int main() {
	ll W; scanf("%d%lld", &n, &W);
	for (int i = 0; i < n; ++i) scanf("%lld%d", &w[i], &v[i]);
	printf("%d\n", dp(0, W));
	return 0;
}

