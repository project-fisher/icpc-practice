// 0.010s/709
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	int t = 0;
	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		++t;
		vector<int> b(n), s(m);
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		for (int i = 0; i < m; ++i) scanf("%d", &s[i]);
		if (n > m) printf("Case %d: %d %d\n", t, n - m, *min_element(b.begin(), b.end());
		else printf("Case %d: 0\n", t);
	}
	return 0;
}

