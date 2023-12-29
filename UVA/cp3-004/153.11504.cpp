// 0.470s/3411
#include <bits/stdc++.h>

using namespace std;

vector<set<int>> adj;
map<int, int> reff;
int nc, sr;
vector<int> s, dfsn, dfsl, vis;

void tarjan(int v) {
	dfsn[v] = dfsl[v] = nc++;
	s.push_back(v);
	vis[v] = 1;
	for (auto u : adj[v]) {
		if (dfsn[u] == -1) tarjan(u);
		if (vis[u]) dfsl[v] = min(dfsl[v], dfsl[u]);
	}
	if (dfsl[v] == dfsn[v]) {
		int id = sr++;
		while (1) {
			int u = s.back(); s.pop_back(); vis[u] = 0;
			reff[u] = id;
			if (u == v) break;
		}
	}
}
			

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; scanf("%d%d", &n, &k);
		adj.assign(n, {});
		reff.clear();
		for (int i = 0; i < k; ++i) {
			int u, v; scanf("%d%d", &u, &v); --u; --v;
			adj[u].insert(v);
		}
		dfsn.assign(n, -1);
		dfsl.resize(n);
		vis.assign(n, 0);
		nc = 0;
		sr = 0;
		for (int i = 0; i < n; ++i) if (dfsn[i] == -1) tarjan(i);
		vector<int> idg(sr, 0);
		for (int i = 0; i < n; ++i) for (auto j : adj[i]) if (reff[i] != reff[j]) ++idg[reff[j]];
		int ans = 0;
		for (auto i : idg) ans += !i;
		printf("%d\n", ans);
	}
	return 0;
}
		
		
		
