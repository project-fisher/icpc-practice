#include <bits/stdc++.h>

#define llu unsigned long long
#define ll long long
#define u unsigned int
using namespace std;

ll count(vector<ll> &a, ll n) {
	u mx = 1 << a.size();
	ll total = 0ll;
	for (u msk = 1; msk < mx; ++msk) {
		u bits = 0;
		ll mult = 1ll;
		for (u i = 0; i < a.size(); ++i) if (msk&(1 << i)) {
			++bits;
			mult *= a[i];
		}
		total += bits&1 ? n/mult : -n/mult;
	}
	return n - total;
}

int main() {
	ll n; int k; scanf("%lld%d", &n, &k);
	vector<ll> a(k); for (int i = 0; i < k; ++i) scanf("%lld", &a[i]);
	ll l = n, r = n << 4ll;
	ll mid = (l + r) >> 1;
	ll ans;
	while (l <= r) {
		ll c = count(a, mid);
		if (c == n) {
			if (mid == ans) break;
			ans = mid;
			l = n;
			r = mid - 1;
			mid = (l + r) >> 1;
			continue;
		}
		if (c < n) l = mid + 1;
		else r = mid - 1;
		mid = (l + r) >> 1;
	}
	printf("%lld\n", ans);
	return 0;
}


