// 0.010s/2076(3)
#include <bits/stdc++.h>

using namespace std;

vector<set<pair<int, int>>> adj;
bitset<100> vis;
priority_queue<pair<int, pair<int, int>>> pq;
vector<vector<vector<pair<int, int>>>> trees;
vector<int> poss;
int cid, best;

void process(int v) {
	vis.set(v);
	poss[v] = cid;
	for (auto &u : adj[v]) if (!vis[u.first]) pq.push({-u.second, {u.first, v}});
}

bool dfs(int v, int tv, int p) {
	if (v == tv) return 1;
	bool f = 0;
	for (auto i : trees[cid][v]) {
		if (i.first != p) {
			f |= dfs(i.first, tv, v);
			if (f) {
				best = max(best, i.second);
				break;
			}
		}
	}
	return f;
}


int main() {
	int n, k, q;
	int T = 0;
	while (scanf("%d%d%d", &n, &k, &q) && (n || k || q)) {
		adj.assign(n, {});
		for (int i = 0; i < k; ++i) {
			int v, u, d; scanf("%d%d%d", &v, &u, &d); --v; --u;
			adj[v].insert({u, d});
			adj[u].insert({v, d});
		}
		vis.reset();
		trees.clear();
		poss.resize(n);
		cid = 0;
		for (int i = 0; i < n; ++i) if (!vis[i]) {
			trees.push_back({});
			trees.back().assign(n, {});
			process(i);
			while (!pq.empty()) {
				int d = pq.top().first; pair<int, int> vu = pq.top().second; pq.pop();
				if (!vis[vu.first]) {
					process(vu.first);
					trees.back()[vu.first].push_back({vu.second, -d});
					trees.back()[vu.second].push_back({vu.first, -d});
				}
			}
			++cid;
		}
		if (T) puts("");
		printf("Case #%d\n", ++T);
		for (int i = 0; i < q; ++i) {
			int u, v; scanf("%d%d", &u, &v); --v; --u;
			if (poss[u] != poss[v]) puts("no path");
			else {
				cid = poss[v];
				best = 0;
				dfs(u, v, u);
				printf("%d\n", best);
			}
		}
	}
	return 0;
}
