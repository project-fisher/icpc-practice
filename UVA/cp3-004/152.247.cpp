// 0.010s/1903
#include <bits/stdc++.h>

using namespace std;

vector<set<int>> adj;
int dfsnc;
vector<int> dfsn, dfsl, vis, s;
vector<vector<int>> ans;

void tarjan(int v) {
	dfsl[v] = dfsn[v] = dfsnc++;
	s.push_back(v);
	vis[v] = 1;
	for (auto i : adj[v]) {
		if (dfsn[i] == -1) tarjan(i);
		if (vis[i]) dfsl[v] = min(dfsl[v], dfsl[i]);
	}
	if (dfsl[v] == dfsn[v]) {
		ans.push_back({});
		while (1) {
			int u = s.back(); s.pop_back(); vis[u] = 0;
			ans.back().push_back(u);
			if (u == v) break;
		}
	}
}

int main() {
	int n, k, T = 0;
	while (scanf("%d%d", &n, &k) && (n || k)) {
		char buffer[26];
		char buffer2[26];
		map<string, int> ntp;
		vector<string> ptn;
		adj.assign(n, set<int>());
		for (int i = 0; i < k; ++i) {
			int p1, p2;
			scanf("%s", buffer);
			string t(buffer);
			if (!ntp.count(t)) {
				ntp[t] = ptn.size();
				ptn.push_back(t);
			}
			p1 = ntp[t];
			scanf("%s", buffer2);
			string tp(buffer2);
			if (!ntp.count(tp)) {
				ntp[tp] = ptn.size();
				ptn.push_back(tp);
			}
			p2 = ntp[tp];
			adj[p1].insert(p2);
		}
		dfsnc = 0;
		dfsn.assign(n, -1); dfsl.resize(n); vis.assign(n, 0);
		s.clear(); ans.clear();
		for (int i = 0; i < n; ++i) if (dfsn[i] == -1) tarjan(i);
		if (T) puts("");
		printf("Calling circles for data set %d:\n", ++T);
		for (auto &i : ans) {
			bool f = 1;
			for (auto j : i) {
				if (f) f = 0;
				else printf(", ");
				printf("%s", ptn[j].c_str());
			}
			puts("");
		}
	}
	return 0;
}
