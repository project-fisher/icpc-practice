// 0.000s/1332
#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

int m;

bool mems[51][51];
llu mem[51][51];

llu bc(int n, int k) {
	if (n == 0) return k ? 0 : 1;
	if (n < 0 || k == 0) return 0;
	if (mems[n][k]) return mem[n][k];
	llu sum = 0;
	for (int i = 1; i <= m; ++i) sum += bc(n - i, k - 1);
	mems[n][k] = 1;
	return mem[n][k] = sum;
}

int main() {
	int n, k;
	while (scanf("%d%d%d", &n, &k, &m) != -1) {
		memset(mems, 0, sizeof(mems));
		printf("%llu\n", bc(n, k));
	}
	return 0;
}
