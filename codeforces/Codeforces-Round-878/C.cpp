#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll no_cons(int s, int e, int k) {
	ll n = max(0, e - s - k + 1);
	return (n*(n + 1)) >> 1;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, k; ll q; scanf("%d%d%lld", &n, &k, &q);
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
		bool searching = 1;
		int s, e;
		ll ans = 0;
		for (int i = 0; i < n; ++i) {
			if (searching) {
				if (a[i] <= q) {
					s = i;
					searching = 0;
				}
			} else if (a[i] > q) {
				searching = 1;
				e = i;
				ans += no_cons(s, e, k);
			}
		}
		if (!searching) {
			e = n;
			ans += no_cons(s, e, k);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
