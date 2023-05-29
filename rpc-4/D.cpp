#include <bits/stdc++.h>

using namespace std;

int main() {
	long n, q; scanf("%ld%ld", &n, &q);
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	sort(a.begin(), a.end());
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			long long x; scanf("%lld", &x);
			if (x > a.back()) a.emplace_back(x);
			else *lower_bound(a.begin(), a.end(), x) = x;
		} else {
			long long x, y; scanf("%lld%lld", &x, &y);
			printf("%ld\n", (long)distance(lower_bound(a.begin(), a.end(), x), upper_bound(a.begin(), a.end(), y)));
		}
	}
	return 0;
}
