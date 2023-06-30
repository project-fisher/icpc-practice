// 0.260s/913
#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
using namespace std;

int main() {
	int t; scanf("%d", &t);
	ll data[102][102];
	ll sum[102][102] = {0};
	for (int T = 1; T <= t; ++T) {
		int n, m; ll k; scanf("%d%d%lld", &n, &m, &k);
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) scanf("%lld", &data[i][j]);
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + data[i][j];
		int best_area = INT_MIN;
		ll best_price = LLONG_MAX;
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) if (data[i][j] <= k) for (int ip = i; ip <= n; ++ip) {
			int inf = 0, sup = m;
			int mid = (inf + sup) >> 1, area = -1;
			ll best = 0;
			while (inf <= sup) {
				ll val = sum[ip][mid] - sum[i - 1][mid] - sum[ip][j - 1] + sum[i - 1][j - 1];
				int at = (ip + 1 - i)*(mid + 1 - j);
				if (mid >= j && val <= k && area <= at && (best > val || area < at)) {
					best = val;
					area = at;
				}
				if (val <= k) inf = mid + 1;
				else sup = mid - 1;
				mid = (inf + sup) >> 1;
			}
			if (area > best_area) {
				best_area = area;
				best_price = best;
			} else if (area == best_area) best_price = min(best_price, best);
		}
		if (best_area == INT_MIN) {
			best_area = 0;
			best_price = 0;
		}
		printf("Case #%d: %d %lld\n", T, best_area, best_price);
	}
	return 0;
}
