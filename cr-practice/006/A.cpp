#include <bits/stdc++.h>

#define llu unsigned long long

using namespace std;

int n, h[100003];

const llu MAX = ULLONG_MAX - 10001;

llu memo[100003];
bitset<100003> memo_s = 0;

llu dp(int pos) {
	if (pos == n - 1) return 0;
	if (pos == n) return MAX;
	if (memo_s[pos]) return memo[pos];
	memo_s.set(pos);
	return memo[pos] = min(dp(pos + 1) + abs(h[pos] - h[pos + 1]), dp(pos + 2) + abs(h[pos] - h[pos + 2]));
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
	h[n] = h[n - 1];
	printf("%llu\n", dp(0));
	return 0;
}

