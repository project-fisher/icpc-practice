// 0.770s/5386
#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

llu mod = 1000000;

llu mem[101][101];

llu ad(int n, int k) {
	if (k == 1) return 1;
	if (mem[n][k]) return mem[n][k];
	llu sum = 0;
	for (int i = 0; i <= n; ++i) sum = (sum + ad(n - i, k - 1))%mod;
	return mem[n][k] = sum;
}

int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) && (n || k)) {
		memset(mem, 0, sizeof(mem));
		printf("%llu\n", ad(n, k));
	}
	return 0;
}

