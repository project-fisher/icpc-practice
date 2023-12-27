// 0.000s/1136
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> idg;
vector<int> vis;

bool bicolor(int v, bool color) {
	if (vis[v]) return color == vis[v] - 1;
	vis[v] = color + 1;
	for (auto i : adj[v]) if (!bicolor(i, !color)) return 0;
	return 1;
}

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		int u, v;
		adj.assign(n, vector<int>());
		idg.assign(n, 0);
		while (scanf("%d%d", &u, &v) && u-- && v--) {
			++idg[u]; ++idg[v];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vis.assign(n, 0);
		if (!bicolor(0, 0)) {
			puts("NO");
			continue;
		}
		bool ans1 = 1, ans2 = 1;
		for (int i = 0; i < n && ans1; ++i) if ((vis[i] == 1 && idg[i] != 3)) ans1 = 0;
		for (int i = 0; i < n && ans2; ++i) if ((vis[i] == 2 && idg[i] != 3)) ans2 = 0;
		if (ans1 || ans2) puts("YES");
		else puts("NO");
	}
	return 0;
}
