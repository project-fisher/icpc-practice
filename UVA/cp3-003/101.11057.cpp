// 0.010s/1267
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		vector<long> a(n);
		for (int i = 0; i < n; ++i) scanf("%ld", &a[i]);
		long m; scanf("%ld", &m);
		sort(a.begin(), a.end());
		int book;
		for (int i = 0; m - a[i] >= a[i]; ++i) {
			auto it = lower_bound(a.begin(), a.end(), m - a[i]);
			if (it != a.end() && *it == m - a[i]) book = i;
		}
		printf("Peter should buy books whose prices are %ld and %ld.\n\n", a[book], m - a[book]);
	}
	return 0;
}
