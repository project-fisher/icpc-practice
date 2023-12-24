// 0.000s/1704(1)
#include <bits/stdc++.h>

using namespace std;

int s;
char mat[101][101];

int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

void color(int x, int y, int dir) {
	if (x < 0 || y < 0 || x >= s || y >= s) return;
	if (mat[x][y] == '.') return;
	mat[x][y] = '.';
	if (dir == -1) for (int i = 0; i < 4; ++i) color(x + dr[i], y + dc[i], i);
	else color(x + dr[dir], y + dc[dir], dir);
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &s);
		for (int i = 0; i < s; ++i) scanf("%s", mat[i]);
		int ans = 0;
		for (int i = 0; i < s; ++i) for (int j = 0; j < s; ++j) if (mat[i][j] == 'x') {
			++ans;
			color(i, j, -1);
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
