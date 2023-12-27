// 0.000s/1587(1)
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> vis;
int c[2];

bool bicolor(int v, bool color) {
	if (vis[v]) return vis[v] - 1 == color;
	vis[v] = color + 1;
	++c[color];
	for (auto i : adj[v]) if (!bicolor(i, !color)) return 0;
	return 1;
}

int mmin(int a, int b) {
	return !a || !b ? a + b : min(a, b);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d%d", &n, &k);
		c[0] = 0;
		c[1] = 0;
		vis.assign(n, 0);
		adj.assign(n, vector<int>());
		for (int i = 0; i < k; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bool ans = 1;
		int s = 0;
		for (int i = 0; i < n && ans; ++i, c[0] = 0, c[1] = 0) if (!vis[i]) if ((ans = bicolor(i, 0))) s += mmin(c[0], c[1]);
		if (ans) printf("%d\n", s);
		else puts("-1");
	}
	return 0;
}
