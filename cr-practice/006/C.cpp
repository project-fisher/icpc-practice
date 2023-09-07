#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, a[100001], b[100001], c[100001];

const ll MIN = LLONG_MIN;

ll memo[3][100001] = {0};

ll dp(int pos, char prev) {
	if (pos == n) return 0;
	if (memo[prev][pos]) return memo[prev][pos];
	if (!pos) memo[prev][pos] = max(max(dp(pos + 1, 0) + a[pos], dp(pos + 1, 1) + b[pos]), dp(pos + 1, 2) + c[pos]);
	else if (prev == 0) memo[prev][pos] = max(dp(pos + 1, 1) + b[pos], dp(pos + 1, 2) + c[pos]);
	else if (prev == 1) memo[prev][pos] = max(dp(pos + 1, 0) + a[pos], dp(pos + 1, 2) + c[pos]);
	else memo[prev][pos] = max(dp(pos + 1, 1) + b[pos], dp(pos + 1, 0) + a[pos]);
	return memo[prev][pos];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d%d", &a[i], &b[i], &c[i]);
	printf("%lld\n", dp(0, 0));
	return 0;
}
	


