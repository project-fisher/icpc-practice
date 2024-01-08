// 0.030s/3715
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		vector<vector<pair<int, long>>> adj(n);
		for (int i = 0; i < m; ++i) {
			int v, u; long t; scanf("%d%d%ld", &v, &u, &t);
			adj[v].push_back({u, t});
		}
		vector<long> dist(n, LONG_MAX); dist[0] = 0;
		for (int i = n - 1; i >= 0; --i) for (int v = 0; v < n; ++v) for (auto u : adj[v]) dist[u.first] = (dist[v] != LONG_MAX)*min(dist[u.first], dist[v] + u.second);
		bool nc = 0;
		for (int v = 0; v < n && !nc; ++v) for (int j = 0; j < adj[v].size() && !nc; ++j) nc = dist[adj[v][j].first] > dist[v] + adj[v][j].second;
		if (nc) puts("possible");
		else puts("not possible");
	}
	return 0;
}
