// 0.010s/2074
#include <bits/stdc++.h>

using namespace std;


int main() {
	int n; scanf("%d", &n);
	vector<set<int>> adj(n);
	for (int i = 0; i < n; ++i) {
		int k; scanf("%d", &k);
		while (k--) {
			int t; scanf("%d", &t);
			adj[i].insert(t);
		}
	}
	int t; scanf("%d", &t);
	while (t--) {
		int s; scanf("%d", &s);
		if (adj[s].size() == 0) puts("0");
		else {
			vector<int> dist(n, INT_MAX); dist[s] = 0;
			map<int, int> m;
			queue<int> q; q.push(s);
			while (!q.empty()) {
				int c = q.front(); q.pop();
				for (auto i : adj[c]) if (dist[i] == INT_MAX) {
					m[dist[c]]++;
					dist[i] = dist[c] + 1;
					q.push(i);
				}
			}
			int mx = 0, mxp = 0;
			for (auto &i : m) {
				if (i.second > mx) {
					mx = i.second;
					mxp = i.first;
				}
			}
			printf("%d %d\n", mx, mxp + 1);
		}
	}
	return 0;
}
