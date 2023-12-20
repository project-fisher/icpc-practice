// 0.020s/268
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fw(vector<vector<pair<int, int>>> &adj) {
	int n = adj.size();
	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) dist[i][j] = i == j ? 0 : INT_MAX;
		for (auto &j : adj[i]) dist[i][j.first] = min(dist[i][j.first], j.second);
	}
	for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dist[i][j] = min(dist[i][j], dist[i][k] == INT_MAX || dist[k][j] == INT_MAX ? INT_MAX : dist[i][k] + dist[k][j]);
	return dist;
}

int mem[13][1 << 13];
bool mems[13][1 << 13];
int k;
int tadj[13][13];
int saved[13];

int tsp(int pos, int msk) {
	if (msk + 1 == 1 << (k + 1)) return tadj[pos][0];
	if (mems[pos][msk]) return mem[pos][msk];
	int mn = tadj[pos][0];
	for (int i = 0; i <= k; ++i) if (!(msk&(1 << i))) mn = min(mn, tsp(i, msk|(1 << i)) + tadj[pos][i] - saved[i]);
	mems[pos][msk] = 1;
	return mem[pos][msk] = mn;
}

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int c, m; scanf("%d%d", &c, &m);
		++c;
		vector<vector<pair<int, int>>> adj(c);
		for (int i = 0; i < m; ++i) {
			int a, b, e, f; scanf("%d%d%d.%d", &a, &b, &e, &f);
			int d = e*100 + f;
			adj[a].push_back({b, d});
			adj[b].push_back({a, d});
		}
		vector<vector<int>> dist = fw(adj);
		scanf("%d", &k);
		vector<int> op(k + 1); op[0] = 0; for (int i = 1; i <= k; ++i) {
			int t, e;
			scanf("%d%d.%d", &op[i], &t, &e);
			saved[i] = t*100 + e;
		}
		memset(mem, 0, sizeof(mem));
		memset(mems, 0, sizeof(mems));
		for (int i = 0; i <= k; ++i) for (int j = i + 1; j <= k; ++j) tadj[i][j] = tadj[j][i] = dist[op[i]][op[j]];
		int r = tsp(0, 1);
		int s = -r;
		if (s > 0) printf("Daniel can save $%d.%d%d\n", s/100, s/10%10, s%10);
		else puts("Don't leave the house");
	}
	return 0;
}
