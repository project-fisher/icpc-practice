// 0.020s/1399
#include <bits/stdc++.h>

using namespace std;

int adj[100][100] = {0};

const int INF = INT_MAX >> 1;

int main() {
	int t; scanf("%d", &t);
	for (int T = 1; T <= t; ++T) {
		printf("Case %d: ", T);
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i != j) adj[i][j] = INF;
		for (int i = 0; i < m; ++i) {
			int v, u; scanf("%d%d", &v, &u);
			adj[v][u] = 1;
			adj[u][v] = 1; // ????
		}
		int s, e; scanf("%d%d", &s, &e);
		for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		int mx = 0;
		for (int i = 0; i < n; ++i) mx = (adj[s][i] - INF && adj[i][e] - INF) ? max(mx, adj[s][i] + adj[i][e]) : mx;
		printf("%d\n", mx);
	}
	return 0;
}


