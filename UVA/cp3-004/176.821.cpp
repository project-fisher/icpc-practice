// 0.030s/698(1)
#include <bits/stdc++.h>

using namespace std;

int adj[100][100];
const int INF = INT_MAX >> 1;

int main() {
	int v, u;
	int t = 0;
	while (scanf("%d%d", &v, &u) && (v || u)) {
		for (int i = 0; i < 100; ++i) for (int j = 0; j < 100; ++j) adj[i][j] = INF;
		map<int, int> unq;
		int n = 0;
		do {
			if (!unq.count(v)) unq[v] = n++;
			if (!unq.count(u)) unq[u] = n++;
			adj[unq[v]][unq[u]] = 1;
		} while (scanf("%d%d", &v, &u) && (v || u));
		for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
		long double ans = 0;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) ans += i != j && adj[i][j] != INF ? adj[i][j] : 0;
		ans /= max(1, n*(n - 1));
		printf("Case %d: average length between pages = %.3Lf clicks\n", ++t, ans);
	}
	return 0;
}
