// 0.000s/1952(1)
#include <bits/stdc++.h>

using namespace std;

vector<set<int>> adj;
int dfsnc, dfsr, rc;
vector<int> dfsp, dfsl, dfsn, artv;

void art(int v) {
	dfsl[v] = dfsn[v] = dfsnc++;
	for (auto i : adj[v]) {
		if (dfsn[i] == -1) {
			dfsp[i] = v;
			if (v == dfsr) ++rc;
			art(i);
			if (dfsl[i] >= dfsn[v]) artv[v] = 1;
			dfsl[v] = min(dfsl[v], dfsl[i]);
		} else if (i != dfsp[v]) dfsl[v] = min(dfsl[v], dfsn[i]);
	}
}

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		int k;
		adj.assign(n, set<int>());
		dfsnc = 0; dfsn.assign(n, -1); dfsl.assign(n, 0); dfsp.assign(n, -1); artv.assign(n, 0);
		while (scanf("%d", &k) && k--) {
			char c = -1;
			int b = 0;
			while ((c = getchar()) == ' ');
			while (c != '\n') {
				b = c - '0';
				while ((c = getchar()) <= '9' && c >= '0') b = b*10 + c - '0';
				--b;
				adj[k].insert(b);
				adj[b].insert(k);
				while (c != '\n' && (c = getchar()) == ' ');
			}
		}
		for (int i = 0; i < n; ++i) {
			if (dfsn[i] == -1) {
				dfsr = i; rc = 0; art(i);
				artv[dfsr] = rc > 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) ans += artv[i];
		printf("%d\n", ans);
	}
	return 0;
}
