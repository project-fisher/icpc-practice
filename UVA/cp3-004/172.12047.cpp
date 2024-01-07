// 0.220s/988(1)
#include <bits/stdc++.h>

using namespace std;

void dij(vector<long> &dist, vector<set<pair<int, long>>> &adj, int k, long p) {
	dist[k] = 0;
	set<pair<int, int>> s = {{0, k}};
	while (!s.empty()) {
		auto f = *s.begin(); s.erase(s.begin());
		long a = f.first; int b = f.second;
		if (a > dist[b]) continue;
		for (auto &i : adj[b]) {
			int c = i.first; long d = i.second + a;
			if (d < p && d < dist[c]) {
				dist[c] = d;
				s.insert({d, c});
			}
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m, s, t; long p; scanf("%d%d%d%d%ld", &n, &m, &s, &t, &p); --s; --t;
		vector<set<pair<int, long>>> adj(n), adjr(n);
		for (int i = 0; i < m; ++i) {
			int v, u; long c; scanf("%d%d%ld", &v, &u, &c); --v; --u;
			// I had the thought of using double dij but didn't realize that I could you a reverse graph....
			// Instead submitted a TLE using a state-space graph with maps for memory management.
			adj[v].insert({u, c});
			adjr[u].insert({v, c});
		}
		vector<long> dist(n, LONG_MAX), distr(n, LONG_MAX);
		dij(dist, adj, s, p);
		dij(distr, adjr, t, p);
		if (s == t) puts("0");
		else {
			long mx = -1;
			for (int v = 0; v < n; ++v) for (auto &i : adj[v]) {
				int u = i.first; long r = i.second;
				if (dist[v] != LONG_MAX && distr[u] != LONG_MAX && dist[v] + distr[u] + r <= p) mx = max(mx,  r);
			}
			printf("%ld\n", mx);
		}
	}
	return 0;
}
