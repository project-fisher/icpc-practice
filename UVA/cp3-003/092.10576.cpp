// 0.000s/824
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll a, b;

ll backtrack(int n, ll sum, ll subsum, ll msk) {
	if (n == 12) return sum;
	if (n < 4) return max(backtrack(n + 1, sum + a, subsum + a, msk|(1 << n)), backtrack(n + 1, sum - b, subsum - b, msk));
	ll best = numeric_limits<ll>::min();
	if (subsum + a < 0) best = max(best, backtrack(n + 1, sum + a, subsum + a + (msk&(1 << (n - 4)) ? -a : b), msk|(1 << n)));
	if (subsum - b < 0) best = max(best, backtrack(n + 1, sum - b, subsum - b + (msk&(1 << (n - 4)) ? -a : b), msk));
	return best;
}

int main() {
	while (scanf("%lld%lld", &a, &b) == 2) {
		ll ans = backtrack(0, 0, 0, 0);
		if (ans < 0) printf("Deficit\n");
		else printf("%lld\n", ans);
	}
	return 0;
}
