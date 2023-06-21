// 0.020s/438(3)
// Had like 3 runtime exceptions. Why? I have no idea. I ended up changing -inf to LLONG_MIN and instead of temp = LLONG_MIN I used temp = 0;
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int t; scanf("%d", &t);
	ll data[25][25][25] = {0};
	ll sum[25][25][25] = {0};
	while (t--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		for (int i = 1; i <= a; ++i) for (int j = 1; j <= b; ++j) for (int k = 1; k <= c; ++k) scanf("%lld", &data[i][j][k]);
		for (int i = 1; i <= a; ++i) for (int j = 1; j <= b; ++j) for (int k = 1; k <= c; ++k) sum[i][j][k] = sum[i][j - 1][k] - sum[i - 1][j - 1][k] + sum[i - 1][j][k] + data[i][j][k];
		ll total = LLONG_MIN;
		for (int i = 0; i < a; ++i) for (int ip = i + 1; ip <= a; ++ip) for (int j = 0; j < b; ++j) for (int jp = j + 1; jp <= b; ++jp) {
			ll temp = 0;
			for (int k = 1; k <= c; ++k) {
			       ll s = sum[ip][jp][k] - sum[ip][j][k] - sum[i][jp][k] + sum[i][j][k];
			       temp = max(s, temp + s);
			       total = max(total, temp);
			}
		}
		printf("%lld\n", total);
		if (t) printf("\n");
	}
	return 0;
}

