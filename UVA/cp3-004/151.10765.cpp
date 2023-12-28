// 0.030s/1264(1)
#include <bits/stdc++.h>

using namespace std;

vector<set<int>> adj;
int cnt;
vector<int> dfsp, dfsn, dfsl, artv;

void art(int v) {
	dfsn[v] = dfsl[v] = cnt++;
	for (auto i : adj[v]) {
		if (dfsn[i] == -1) {
			dfsp[i] = v;
			art(i);
			if (dfsl[i] >= dfsn[v]) ++artv[v];
			dfsl[v] = min(dfsl[v], dfsl[i]);
		} else if (i != dfsp[v]) dfsl[v] = min(dfsl[v], dfsn[i]);
	}
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && (n++ || m)) {
		int u, v;
		adj.assign(n, set<int>());
		while (scanf("%d%d", &u, &v) && (u != -1 || v != -1)) {
			adj[u].insert(v);
			adj[v].insert(u);
		}
		adj[n - 1].insert(0);
		adj[0].insert(n - 1);
		dfsp.assign(n, -1);
		dfsn.assign(n, -1);
		dfsl.resize(n);
		artv.assign(n, 0);
		cnt = 0;
		art(n - 1);
		vector<pair<int, int>> ans(n); for (int i = 0; i < n; ++i) ans[i] = {-artv[i], i};
		++ans[0].first;
		ans[n - 1].first = 0;
		sort(ans.begin(), ans.end());
		for (int i = 0; i < m; ++i) printf("%d %d\n", ans[i].second, -ans[i].first + 1);
		puts("");
	}
	return 0;
}
