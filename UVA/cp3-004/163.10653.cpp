// 0.310s/2366
#include <bits/stdc++.h>
#define lu unsigned long

using namespace std;

lu mp[1000][1000];
int dr[4] = {0, -1, 0, 1}, dc[4] = {1, 0, -1, 0};

int main() {
	int r, c;
	while (scanf("%d%d", &r, &c) && (r || c)) {
		memset(mp, 0, sizeof(mp));
		int k; scanf("%d", &k);
		for (int i = 0; i < k; ++i) {
			int rr, n; scanf("%d%d", &rr, &n);
			for (int j = 0; j < n; ++j) {
				int p; scanf("%d", &p);
				mp[rr][p] = ULONG_MAX;
			}
		}
		int sx, sy, ex, ey; scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		mp[sx][sy] = 1;
		queue<pair<int, int>> q; q.push({sx, sy});
		bool nf = 1;
		while (!q.empty() && nf) {
			int x = q.front().first, y = q.front().second; q.pop();
			for (int i = 0; i < 4; ++i) {
				int tx = x + dr[i], ty = y + dc[i];
				if (tx >= 0 && tx < r && ty >= 0 && ty < c && mp[tx][ty] == 0) {
					mp[tx][ty] = mp[x][y] + 1;
					q.push({tx, ty});
					nf &= tx != ex || ty != ey;	
				}
			}
		}
		printf("%lu\n", mp[ex][ey] - 1);
	}
	return 0;
}
