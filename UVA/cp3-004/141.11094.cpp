// 0.000s/2832(1)
#include <bits/stdc++.h>

using namespace std;

int m, n;
bool mat[21][21];

int dc[] = {0, 1, 0, -1}, dr[] = {1, 0, -1, 0};

int color(int x, int y, int oc, int nc) {
	if (x < 0 || x >= m) return 0;
	y = (n + y%n)%n;
	if (mat[x][y] != oc) return 0;
	mat[x][y] = nc;
	int ans = 1;
	for (int d = 0; d < 4; ++d) ans += color(x + dc[d], y + dr[d], oc, nc);
	return ans;
}

int main() {
	char buffer[21];
	while (scanf("%d%d", &m, &n) == 2) {
		char c = -1;
		for (int i = 0; i < m; ++i) {
			scanf("%s", buffer);
			if (c == -1) c = buffer[0];
			for (int j = 0; j < n; ++j) mat[i][j] = buffer[j] == c;
		}
		int x, y; scanf("%d%d", &x, &y);
		bool t = mat[x][y];
		bool nt = !t;
		color(x, y, t, nt);
		int mx = 0;
		for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) mx = max(mx, color(i, j, t, nt));
		printf("%d\n", mx);
	}
	return 0;
}


