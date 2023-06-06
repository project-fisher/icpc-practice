#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		llu n, k; scanf("%llu%llu", &n, &k);
		llu ans = 1;
		llu r = 1, o = n;
		while (o >>= 1) ++r;
		if (r > k) n = (1 << k) - 1;
		while (n) {
			llu r = 1, o = n;
			while (o >>= 1) ++r;
			ans += 1 << (min(r, k) - 1);
			n -= 1 << (min(r, k) - 1);
		}
		printf("%llu\n", ans);
	}
	return 0;
}
