#include <bits/stdc++.h>

using namespace std;

int n, n2;

double p[3000], memo[3000][3000];
bitset<9000000> memo_s = 0;

double dp(int pos, int total) {
	if (n2 <= pos - total) return 0.0f;
	if (pos == n) return 1.0f;
	if (memo_s[pos*3000 + total]) return memo[pos][total];
	memo_s.set(pos*3000 + total);
	return memo[pos][total] = p[pos]*dp(pos + 1, total + 1) + (1 - p[pos])*dp(pos + 1, total);
}

int main() {
	scanf("%d", &n);
	n2 = n/2 + (n&1);
	for (int i = 0; i < n; ++i) scanf("%lf", &p[i]);
	printf("%.10lf\n", dp(0, 0));
	return 0;
}
	
