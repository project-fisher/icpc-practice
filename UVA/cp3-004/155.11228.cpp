// 0.240s/1822(1)
#include <bits/stdc++.h>

using namespace std;

long adj[1000][1000];
bitset<1001> vis;
priority_queue<pair<long, pair<int, int>>, vector<pair<long, pair<int, int>>>, greater<pair<long, pair<int, int>>>> pq;
int n;

void process(int v) {
	vis.set(v);
	for (int i = 0; i < n; ++i) if (i != v && !vis[i]) pq.push({adj[v][i], {i, v}});
}

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		vis.reset();
		int r; scanf("%d%d", &n, &r);
		long rr = r*r;
		vector<pair<int, int>> d;
		for (int i = 0; i < n; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			for (int j = 0; j < d.size(); ++j) {
				long dif1 = x - d[j].first, dif2 = y - d[j].second;
				long dist = dif1*dif1 + dif2*dif2;
				adj[d.size()][j] = adj[j][d.size()] = dist;
			}
			d.push_back({x, y});
		}
		process(0);
		// prim
		long double sp = 0, lp = 0;
		vector<vector<int>> adjl(n);
		while (!pq.empty()) {
			long d = pq.top().first; int v = pq.top().second.first, u = pq.top().second.second;
			pq.pop();
			if (!vis[v]) {
				process(v);
				adjl[v].push_back(u);
				adjl[u].push_back(v);
				if (d <= rr) sp += sqrt(1.0L*d);
				else lp += sqrt(1.0L*d);
			}
		}
		int states = 1;
		queue<pair<int, int>> q;
		for (auto i : adjl[0]) q.push({i, 0});
		vis.reset();
		vis.set(0);
		while (!q.empty()) {
			int v = q.front().first, u = q.front().second; q.pop();
			vis.set(v);
			for (auto i : adjl[v]) if (!vis[i]) q.push({i, v});
			if (adj[v][u] > rr) ++states;
		}
		printf("Case #%d: %d %lld %lld\n", t, states, llround(sp), llround(lp));
	}
	return 0;
}
