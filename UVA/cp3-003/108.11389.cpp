// 0.010s/3496
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, d, r;
	while (scanf("%d%d%d", &n, &d, &r) == 3 && n) {
		vector<int> m(n), e(n);
		for (int i = 0; i < n; ++i) scanf("%d", &m[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &e[i]);
		sort(m.begin(), m.end());
		sort(e.begin(), e.end());
		int total_over = 0;
		for (int i = 0; i < n; ++i) total_over += max(0, e[i] + m[n - i - 1] - d);
		printf("%d\n", total_over*r);
	}
	return 0;
}
