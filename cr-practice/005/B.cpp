#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<vector<bool>> g(n, vector<bool>(n)); for (auto &i : g) fill(i.begin(), i.end(), 0);
	for (int i = 0; i < m; ++i) {
		int a, b; scanf("%d%d", &a, &b); --a; --b;
		g[a][b] = 1;
		g[b][a] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (!g[i][j]) continue;
			for (int k = j + 1; k < n; ++k)	cnt += g[j][k] && g[k][i];
		}
	}
	printf("%d\n", cnt);
	return 0;
}
