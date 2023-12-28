// 0.000s/2036
#include <bits/stdc++.h>

using namespace std;

vector<set<int>> adj;
int dfsnc;
vector<int> dfsp, dfsn, dfsl;
vector<pair<int, int>> ans;

void art(int v) {
	dfsl[v] = dfsn[v] = dfsnc++;
	for (auto i : adj[v]) {
		if (dfsn[i] == -1) {
			dfsp[i] = v;
			art(i);
			if (dfsl[i] > dfsn[v]) ans.push_back({min(i, v), max(i, v)});
			dfsl[v] = min(dfsl[v], dfsl[i]);
		} else if (i != dfsp[v]) dfsl[v] = min(dfsl[v], dfsn[i]);
	}
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		adj.assign(n, set<int>());
		for (int i = 0; i < n; ++i) {
			int k, c; scanf("%d (%d)", &k, &c);
			for (int i = 0; i < c; ++i) {
				int v; scanf("%d", &v);
				adj[k].insert(v);
				adj[v].insert(k);
			}
		}
		ans.clear();
		dfsnc = 0;
		dfsp.assign(n, -1);
		dfsn.assign(n, -1);
		dfsl.resize(n);
		for (int i = 0; i < n; ++i) if (dfsn[i] == -1) art(i);
		sort(ans.begin(), ans.end());
		auto l = unique(ans.begin(), ans.end());
		ans.erase(l, ans.end());
		printf("%d critical links\n", ans.size());
		for (auto pr : ans) printf("%d - %d\n", pr.first, pr.second);
		puts("");
	}
	return 0;
}
