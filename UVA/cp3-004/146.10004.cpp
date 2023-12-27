// 0.000s/8477
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
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
		int k; scanf("%d", &k);
		adj.assign(n, vector<int>());
		for (int i = 0; i < k; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vis.assign(n, 0);
		bool ans = 1;
		for (int i = 0; i < n && ans; ++i) if (!vis[i]) ans = bicolor(i, 0);
		if (ans) puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
	}
	return 0;
}
