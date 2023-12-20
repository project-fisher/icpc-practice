// 0.000s/1354
#include <bits/stdc++.h>

using namespace std;

int w[1000][10];
int x;
int mem[1000][10];

const int inf = INT_MAX - 1000;

int fp(int pos, int alt) {
	if (pos == x) return alt ? inf : 0;
	if (mem[pos][alt]) return mem[pos][alt];
	int r;
	int mn = (r = fp(pos + 1, alt)) == inf ? inf : r + 30;
	if (alt < 9) mn = min(mn, (r = fp(pos + 1, alt + 1)) == inf ? inf : r + 60);
	if (alt) mn = min(mn, (r = fp(pos + 1, alt - 1)) == inf ? inf : r + 20);
	return mem[pos][alt] = mn - w[pos][alt];
}

int main() {
	int n; scanf("%d", &n);
	for (int t = 0; t < n; ++t) {
		scanf("%d", &x);
		x /= 100;
		for (int i = 9; i >= 0; --i) for (int j = 0; j < x; ++j) scanf("%d", &w[j][i]);
		memset(mem, 0, sizeof(mem));
		printf("%d\n", fp(0, 0));
		puts("");
	}
	return 0;
}
