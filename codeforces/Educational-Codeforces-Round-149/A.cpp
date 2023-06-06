#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll x, k; scanf("%lld%lld", &x, &k);
		ll n = x%k ? 1 : 2;
		printf("%lld\n", n);
		if (n == 1) printf("%lld\n", x);
		else printf("%lld %lld\n", x - k + 1, k - 1);
	}
	return 0;
}
