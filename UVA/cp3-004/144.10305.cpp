// 0.000s/8611
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bitset<101> vis;
vector<int> ans;

void dfs(int v) {
	vis.set(v);
	for (auto i : adj[v]) if (!vis[i]) dfs(i);
	ans.push_back(v);
}

int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) && (n || k)) {
		adj.assign(n, vector<int>());
		vector<int> idg(n, 0);
		for (int i = 0; i < k; ++i) {
			int a, b; scanf("%d%d", &a, &b); --a; --b;
			adj[a].push_back(b);
			++idg[b];
		}
		ans.clear();
		vis.reset();
		for (int i = 0; i < n; ++i) if (!idg[i]) dfs(i);
		for (int i = n - 1; i >= 0; --i) {
			if (i != n - 1) putchar(' ');
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	return 0;
}

