#include <bits/stdc++.h>

#define llu unsigned long long

using namespace std;

int n, k, h[100103];

const llu MAX = ULLONG_MAX - INT_MAX - 1;

llu memo[100003];
bitset<100003> memo_s = 0;

llu dp(int pos) {
	if (pos == n - 1) return 0;
	if (pos >= n) return MAX;
	if (memo_s[pos]) return memo[pos];
	memo_s.set(pos);
	llu mn = MAX;
	for (int i = 1; i <= k; ++i) mn = min(mn, dp(pos + i) + abs(h[pos] - h[pos + i]));
	return memo[pos] = mn;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
	printf("%llu\n", dp(0));
	return 0;
}

