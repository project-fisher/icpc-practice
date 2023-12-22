// 0.010s/422(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	bool gl[101][101];
	bool glv[101][101];
	for (int t = 1; t <= n; ++t) {
		int r, c, m, n; scanf("%d%d%d%d", &r, &c, &m, &n);
		int k; scanf("%d", &k);
		memset(gl, 0, sizeof(gl));
		for (int i = 0; i < k; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			gl[x][y] = 1;
		}
		memset(glv, 0, sizeof(glv));
		queue<pair<int, int>> q;
		q.push({0, 0});
		int even = 0, odd = 0;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			if (glv[x][y]) continue;
			glv[x][y] = 1;
			int k = 0;
			for (int i = -1; i < 2; i += 2) for (int j = -1; j < 2; j += 2) {
				int xp1 = x + i*m, yp1 = y + j*n;
				int xp2 = x + i*n, yp2 = y + j*m;
				if (n == 0 || m == 0) {
					int ar = n + m;	
					int xp = x, yp = y;
					if (i == -1) xp += j*ar;
					else yp += j*ar;
					if (!(gl[xp][yp] || xp < 0 || yp < 0 || xp >= r || yp >= c)) {
						++k;
						q.push({xp, yp});
					}
				} else {
					if (!(gl[xp1][yp1] || xp1 < 0 || yp1 < 0 || xp1 >= r || yp1 >= c)) {
						++k;
						q.push({xp1, yp1});
					}
					if (n != m) {
						if (!(gl[xp2][yp2] || xp2 < 0 || yp2 < 0 || xp2 >= r || yp2 >= c)) {
							++k;
							q.push({xp2, yp2});
						}
					}
				}
			}
			if (k&1) ++odd;
			else ++even;
		}
		printf("Case %d: %d %d\n", t, even, odd);
	}
	return 0;
}
