// 0.080s/591
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int w[5][5] = {0};
		int g[5][5];
		for (int i = 0; i < n; ++i) {
			int x, y, z; scanf("%d%d%d", &x, &y, &z);
			w[x][y] = z;
			g[i/5][i%5] = i;
		}
		unsigned int mn = -1;
		int f[5];
		for (int a = 20; a >= 0; --a)
			for (int b = 21; b > a; --b)
				for (int c = 22; c > b; --c)
					for (int d = 23; d > c; --d)
						for (int e = 24; e > d; --e) {
							unsigned int z = 0;
							for (int i = 0; i < 5; ++i)
								for (int j = 0; j < 5; ++j) {
									unsigned int dp = -1;
									dp = min(dp, abs(a/5 - i) + abs(a%5 - j) + 1u);
									dp = min(dp, abs(b/5 - i) + abs(b%5 - j) + 1u);
									dp = min(dp, abs(c/5 - i) + abs(c%5 - j) + 1u);
									dp = min(dp, abs(d/5 - i) + abs(d%5 - j) + 1u);
									dp = min(dp, abs(e/5 - i) + abs(e%5 - j) + 1u);
									z += dp*w[i][j];
								}
							if (z <= mn) {
								f[0] = a;
								f[1] = b;
								f[2] = c;
								f[3] = d;
								f[4] = e;
								mn = z;
							}
						}
		printf("%d %d %d %d %d\n", f[0], f[1], f[2], f[3], f[4]);
	}
	return 0;
}
