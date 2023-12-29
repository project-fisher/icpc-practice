// 0.240s/3054
#include <bits/stdc++.h>

using namespace std;

vector<set<int>> adj;
int nc, ac;
vector<int> s, vis, dfsn, dfsl;

void tarjan(int v) {
	dfsn[v] = dfsl[v] = nc++;
	s.push_back(v);
	vis[v] = 1;
	for (auto u : adj[v]) {
		if (dfsn[u] == -1) tarjan(u);
		if (vis[u]) dfsl[v] = min(dfsl[v], dfsl[u]);
	}
	if (dfsn[v] == dfsl[v]) {
		++ac;
		while (1) {
			int u = s.back(); s.pop_back(); vis[u] = 0;
			if (u == v) break;
		}
	}
}

int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) && (n || k)) {
		adj.assign(n, {});
		for (int i = 0; i < k; ++i) {
			int v, u, t; scanf("%d%d%d", &v, &u, &t); --v; --u;
			adj[v].insert(u);
			if (t - 1) adj[u].insert(v);
		}
		nc = 0; ac = 0;
		vis.assign(n, 0);
		dfsn.assign(n, -1);
		dfsl.resize(n);
		for (int i = 0; i < n; ++i) if (dfsn[i] == -1) tarjan(i);
		printf("%d\n", ac == 1);
	}
	return 0;
}
