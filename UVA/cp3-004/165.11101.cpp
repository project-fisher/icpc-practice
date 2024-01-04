// 0.270s/467
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int mxx, mxy;

bool valid(int x, int y) {
	return x >= 0 && x < mxx && y >= 0 && y < mxy;
}

int main() {
	int p;
	while (scanf("%d", &p) && p) {
		mxx = INT_MIN; mxy = INT_MIN;
		int mnx = INT_MAX, mny = INT_MAX;
		vector<pair<int, int>> a, b;
		for (int i = 0; i < p; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			mxx = max(mxx, x); mxy = max(mxy, y);
			mnx = min(mnx, x); mny = min(mny, y);
			a.push_back({x, y});
		}
		scanf("%d", &p);
		for (int i = 0; i < p; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			mxx = max(mxx, x); mxy = max(mxy, y);
			mnx = min(mnx, x); mny = min(mny, y);
			b.push_back({x, y});
		}
		mxx -= mnx - 1; mxy -= mny - 1;
		for (auto &i : a) i = {i.first - mnx, i.second - mny};
		for (auto &i : b) i = {i.first - mnx, i.second - mny};
		vector<vector<int>> cost1(mxx, vector<int>(mxy, INT_MAX)), cost2(mxx, vector<int>(mxy, INT_MAX));
		queue<pair<int, int>> q1, q2;	
		for (auto &i : a) {
			q1.push(i);
			cost1[i.first][i.second] = 0;
		}
		for (auto &i : b) {
			q2.push(i);
			cost2[i.first][i.second] = 0;
		}
		int ans = INT_MAX;
		while (ans == INT_MAX && !(q1.empty() && q2.empty())) {
			int x = q1.front().first, y = q1.front().second; q1.pop();
			for (int i = 0; i < 4; ++i) {
				int tx = x + dx[i], ty = y + dy[i];
				if (valid(tx, ty) && cost1[tx][ty] == INT_MAX) {
					if (cost2[tx][ty] != INT_MAX) {
						ans = cost1[x][y] + cost2[tx][ty] + 1;
						break;
					}
					cost1[tx][ty] = cost1[x][y] + 1;
					q1.push({tx, ty});
				}
			}
			if (ans != INT_MAX) break;
			x = q2.front().first; y = q2.front().second; q2.pop();
			for (int i = 0; i < 4; ++i) {
				int tx = x + dx[i], ty = y + dy[i];
				if (valid(tx, ty) && cost2[tx][ty] == INT_MAX) {
					if (cost1[tx][ty] != INT_MAX) {
						ans = cost2[x][y] + cost1[tx][ty] + 1;
						break;
					}
					cost2[tx][ty] = cost2[x][y] + 1;
					q2.push({tx, ty});
				}
			}
		}
		if (ans == INT_MAX) puts("-1");
		else printf("%d\n", ans);
	}
	return 0;
}
