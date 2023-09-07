#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> G;
bitset<100001> inicios;
bitset<100001> finales;

int memo[100001] = {0};

int dp(int node) {
	if (finales[node]) return 0;
	if (memo[node]) return memo[node];
	int mx = 0;
	for (int i : G[node]) mx = max(mx, dp(i) + 1);
	return memo[node] = mx;
}

int main() {
	int m; scanf("%d%d", &n, &m);
	G.resize(n);
	inicios.set();
	finales.set();
	while (m--) {
		int x, y; scanf("%d%d", &x, &y); --x; --y;
		G[x].push_back(y);
		finales.reset(x);
		inicios.reset(y);
	}
	int mx = 0;
	for (int i = 0; i < n; ++i) if (inicios[i]) mx = max(mx, dp(i));
	printf("%d\n", mx);
	return 0;
}
