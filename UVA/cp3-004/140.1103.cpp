// 0.020s/1019
#include <bits/stdc++.h>

using namespace std;

int x, y;
int mat[201][201];

int dr[] = {0, 1, 0, -1}, dc[] = {1,0,-1, 0};
set<int> vis;

void floodfill(int r, int c, int c1, int c2) {
	if (r < 0 || r >= x || c < 0 || c >= y) {
		vis.insert(-2);
		return;
	}
	if (mat[r][c] != c1) {
		if (mat[r][c] != c2) vis.insert(mat[r][c]);
		return;
	}
	mat[r][c] = c2;
	for (int d = 0; d < 4; ++d) floodfill(r + dr[d], c + dc[d], c1, c2);
}

int ff(int r, int c, int c1, int c2) {
	vis = {};
	floodfill(r, c, c1, c2);
	return vis.size();
}

int main() {
	int T = 1;
	while (scanf("%d%d", &x, &y) && (x || y)) {
		char buffer[201];
		for (int i = 0; i < x; ++i) {
			scanf("%s", buffer);
			for (int j = 0; j < y; ++j) {
				int v;
				if (buffer[j] <= '9') v = buffer[j] - '0';				
				else v = buffer[j] + 10 - 'a';
				for (int k = 0; k < 4; ++k) {
					if (v&(1 << (3 - k))) mat[i][4*j + k] = 1;
					else mat[i][4*j + k] = -1;
				}
			}
		}
		y *= 4;
		int cnt = 2;
		for (int i = 0; i < x; ++i) for (int j = 0; j < y; ++j) if (mat[i][j] == 1) ff(i, j, 1, cnt++);
		vector<int> rr(cnt - 2, 0);
		for (int i = 0; i < x; ++i) for (int j = 0; j < y; ++j) if (mat[i][j] == -1) {
			cnt = ff(i, j, -1, 0);
			if (cnt == 1) ++rr[(*vis.begin()) - 2];
		}
		int r[6] = {0};
		for (auto i : rr) ++r[i];
		printf("Case %d: ", T++);
		for (int i = 0; i < r[1]; ++i) putchar('A');
		for (int i = 0; i < r[5]; ++i) putchar('D');
		for (int i = 0; i < r[3]; ++i) putchar('J');
		for (int i = 0; i < r[2]; ++i) putchar('K');
		for (int i = 0; i < r[4]; ++i) putchar('S');
		for (int i = 0; i < r[0]; ++i) putchar('W');
		puts("");
	}
	return 0;
}
