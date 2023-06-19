// 0.010s/3902
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		vector<int> d(n), k(m);
		for (int i = 0; i < n; ++i) scanf("%d", &d[i]);
		for (int i = 0; i < m; ++i) scanf("%d", &k[i]);
		sort(d.begin(), d.end());
		sort(k.begin(), k.end());
		int gold = 0;
		int ds = 0;
		for (int i = 0; i < m && ds < n; ++i) if (k[i] >= d[ds]) {
			++ds;
			gold += k[i];
		}
		if (ds == n) printf("%d\n", gold);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}
		
