// 1.740s/3330(1)
#include <bits/stdc++.h>

using namespace std;

int mat[999][999], dist[999][999], r, c, vis[999][999];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

bool valid(int i, int j) {
	return i >= 0 && j >= 0 && i < r && j < c;
}

int* access(pair<int, int> p) {
	return &dist[p.first][p.second];
}

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
			scanf("%d", &mat[i][j]);
			dist[i][j] = INT_MAX;
		}
		dist[0][0] = mat[0][0];
		set<pair<int, pair<int, int>>> s = {{mat[0][0], {0, 0}}};
		memset(vis, 0, sizeof(vis));
		while (!s.empty()) {
			pair<int, pair<int, int>> f = *s.begin(); s.erase(s.begin());
			if (vis[f.second.first][f.second.second]) continue;
			vis[f.second.first][f.second.second] = 1;
			for (int i = 0; i < 4; ++i) {
				int tx = f.second.first + dr[i], ty = f.second.second + dc[i];
				if (valid(tx, ty) && *access(f.second) + mat[tx][ty] < *access({tx, ty})) {
					*access({tx, ty}) = *access(f.second) + mat[tx][ty];
					s.insert({*access({tx, ty}), {tx, ty}});
				}
			}
		}
		printf("%d\n", dist[r - 1][c - 1]);
	}
	return 0;
}
