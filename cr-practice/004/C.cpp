#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long

using namespace std;

int main() {
	int nr, x, y, nb; scanf("%d%d%d", &nr, &x, &y);
	nb = nr;
	llu ans = 0;
	llu rb = 1;
	while (nr > 1 || nb > 1) {
		if (nr > 1) {
			ans += rb*x;
			--nr;
		}
		if (nb > 1) {
			rb += ans;
			ans *= y;
			--nb;
		}
	}
	printf("%llu\n", ans);
	return 0;
}
