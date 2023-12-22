// 0.110s/650
#include <bits/stdc++.h>

using namespace std;


int main() {
	int g[50001];
	int vis[50001];
	int n; scanf("%d", &n);
	for (int t = 1; t <= n; ++t) {
		int no; scanf("%d", &no);
		int mx = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < no; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			g[u - 1] = v - 1;
		}
		for (int i = 0; i < no; ++i) {
			if (vis[i]) continue;
			set<int> lvis;
			int dist = 0;
			int c = i;
			do {
				lvis.insert(c);
				++dist;
				c = g[c];
			} while (!(vis[c] || lvis.count(c)));
			int d = i;
			do {
				vis[d] = dist--;
				d = g[d];
			} while (!vis[d]);
			if (lvis.count(c)) {
				int k = g[c];
				while (k != c) {
					vis[k] = vis[c];
					k = g[k];
				}
			} else {
				int k = i;
				while (k != c) {
					vis[k] += vis[c];
					k = g[k];
				}
			}
			if (vis[mx] < vis[i]) mx = i;
		}
		printf("Case %d: %d\n", t, mx + 1);
	}
	return 0;
}
