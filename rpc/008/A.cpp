#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		llu n, d; scanf("%llu%llu", &n, &d);
		llu ans = 1;
		++d;
		llu magic = 1;
		llu worst = n;
		for (; ans < worst; ++ans) {
			llu k = magic*d;
			if (k/magic != d || (magic *= d) >= n) break;
		}
		printf("%llu\n", ans);
	}
	return 0;
}