// 0.000s/1179(1)
#include <bits/stdc++.h>

using namespace std;

int adj[2][26][26];
const int INF = INT_MAX >> 1;

int main() {
	int m;
	while (scanf("%d", &m) && m) {
		for (int k = 0; k < 2; ++k) for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) adj[k][i][j] = INF;
		map<char, int> unq;
		vector<char> ptc;
		int n = 0;
		while (m--) {
			char a, d, v, u; int c; scanf(" %c %c %c %c %d", &a, &d, &v, &u, &c);
			if (!unq.count(v)) {
				unq[v] = n++;
				ptc.push_back(v);
			}
			if (!unq.count(u)) {
				unq[u] = n++;
				ptc.push_back(u);
			}
			adj[a == 'M'][unq[v]][unq[u]] = c;
			if(d == 'B') adj[a == 'M'][unq[u]][unq[v]] = c;
		}
		char x, y; scanf(" %c %c", &x, &y);
		if (!unq.count(x) || !unq.count(y)) {
			if (x == y) printf("0 %c\n", x);
			else puts("You will never meet.");
			continue;
		}
		for (int i = 0; i < n; ++i) {
			adj[0][i][i] = 0;
			adj[1][i][i] = 0;
		}
		for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
			adj[0][i][j] = min(adj[0][i][j], adj[0][i][k] + adj[0][k][j]);
			adj[1][i][j] = min(adj[1][i][j], adj[1][i][k] + adj[1][k][j]);
		}
		int mn = INF;
		set<char> ans;
		if (x == y) {
			ans.insert(x);
			mn = 0;
		}
		int yy = unq[x], yo = unq[y];
		for (int i = 0; i < n; ++i) {
			int s = adj[0][yy][i] + adj[1][yo][i];
			if (s < mn) {
				ans.clear();
				mn = s;
			}
			if (s == mn) ans.insert(ptc[i]);
		}
		if (mn == INF) puts("You will never meet.");
		else {
			printf("%d", mn);
			for (auto i : ans) printf(" %c", i);
			puts("");
		}
	}
	return 0;
}

