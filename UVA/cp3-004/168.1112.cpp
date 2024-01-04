// 0.000s/2131(2)
#include <bits/stdc++.h>
#define ii pair<int, int>

using namespace std;

vector<set<ii>> adj;

int main() {
	int t; scanf("%d", &t);
	for (int T = 0; T < t; ++T) {
		int n, e, tm, k; scanf("%d%d%d%d", &n, &e, &tm, &k); --e;
		adj.assign(n, {});
		for (int i = 0; i < k; ++i) {
			int v, u, t; scanf("%d%d%d", &v, &u, &t); --v; --u;
			adj[u].insert({v, t});
		}
		vector<int> dist(n, INT_MAX);
		dist[e] = 0;
		set<ii> s = {{0, e}};
		while (!s.empty()) {
			ii f = *s.begin(); s.erase(s.begin());
			if (f.first > dist[f.second]) continue;
			for (auto &i : adj[f.second]) {
				if (dist[f.second] + i.second < dist[i.first]) {
					dist[i.first] = dist[f.second] + i.second;
					s.insert({dist[i.first], i.first});
				}
			}
		}
		int cnt = 0;
		if (T) puts("");
		for (auto i : dist) cnt += i <= tm;
		printf("%d\n", cnt);
	}
	return 0;
}
