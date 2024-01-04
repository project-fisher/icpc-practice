// 0.330s/5210
#include <bits/stdc++.h>
#define li pair<long, int>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	for (int Ts = 1; Ts <= t; ++Ts) {
		printf("Case #%d: ", Ts);
		int n, m, S, T; scanf("%d%d%d%d", &n, &m, &S, &T);
		vector<set<li>> adj(n);
		for (int i = 0; i < m; ++i) {
			int v, u; long w; scanf("%d%d%ld", &v, &u, &w);
			adj[v].insert({w, u});
			adj[u].insert({w, v});
		}
		vector<long> dist(n, LONG_MAX);
		dist[S] = 0;
		set<li> s = {{0, S}};
		while (!s.empty()) {
			li f = *s.begin(); s.erase(s.begin());
			if (f.first > dist[f.second]) continue;
			for (auto &i : adj[f.second]) if (dist[f.second] + i.first < dist[i.second]) {
				dist[i.second] = dist[f.second] + i.first;
				s.insert({dist[i.second], i.second});
			}
		}
		if (dist[T] == LONG_MAX) puts("unreachable");
		else printf("%ld\n", dist[T]);
	}
	return 0;
}
