// 0.020s/485
#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

bool world[50][50];
int cost[51][51][4];
int r, c;

bool ioc(int i, int j) {
	if (i <= 0 || j <= 0 || i >= r || j >= c) return 0;
	if (i < r && j < c && world[i][j]) return 0;
	if (i && j < c && world[i - 1][j]) return 0;
	if (i < r && j && world[i][j - 1]) return 0;
	if (i && j && world[i - 1][j - 1]) return 0;
	return 1;
}

map<string, int> sti = {{"north", 0}, {"west", 1}, {"south", 2}, {"east", 3}};

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, -1, 0, 1};

int oric(int i, int j) {
	if (i == j) return 0;
	if ((i + 2)%4 == j) return 2;
	return 1;
}

int main() {
	while (scanf("%d%d", &r, &c) && (r || c)) {
		memset(world, 0, sizeof(world));
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				int v; scanf("%d", &v);
				world[i][j] = v;
			}
		}
		for (int i = 0; i < 51; ++i) for (int j = 0; j < 51; ++j) for (int k = 0; k < 4; ++k) cost[i][j][k] = INT_MAX;
		int sx, sy, ex, ey; scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		char buffer[6]; scanf("%s", buffer);
		int ori = sti[string(buffer)];
		cost[sx][sy][ori] = 0;
		queue<pair<int, pair<int, int>>> q; if (ioc(sx, sy)) q.push({ori, {sx, sy}});
		while (!q.empty()) {
			int o = q.front().first, x = q.front().second.first, y = q.front().second.second; q.pop();
			for (int j = 1; j <= 3; ++j) {
				int tx = x + j*dr[o], ty = y + j*dc[o];
				if (ioc(tx, ty)) {
					if (cost[tx][ty][o] == INT_MAX) {
						cost[tx][ty][o] = cost[x][y][o] + 1;
						q.push({o, {tx, ty}});
					}
				} else break;
			}
			for (int i = 0; i < 4; ++i) if (oric(o, i) == 1 && cost[x][y][i] == INT_MAX) {
				cost[x][y][i] = cost[x][y][o] + 1;
				q.push({i, {x, y}});
			}
		}
		int mn = INT_MAX;
		for (int i = 0; i < 4; ++i) mn = min(mn, cost[ex][ey][i]);
		if (mn == INT_MAX) puts("-1");
		else printf("%d\n", mn);
	}
	return 0;
}
