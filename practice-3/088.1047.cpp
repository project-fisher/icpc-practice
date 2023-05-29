// 0.480s/887(2)
// Favorite problem so far... bitmasks, bitswiddling hacks, IT TAKES O(N) TIME TO CLEAR A VECTOR???
#include <bits/stdc++.h>

#define ul unsigned long

using namespace std;

ul count(ul msk) {
	return (((msk & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f) + ((((msk & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f);
}

int main() {
	int n, k, CASE = 1;
	while (scanf("%d%d", &n, &k) && n) {
		vector<ul> t(n);
		for (int i = 0; i < n; ++i) scanf("%lu", &t[i]);
		int s; scanf("%d", &s);
		vector<pair<ul,ul>> S(s);
		for (int i = 0; i < s; ++i) {
			ul msk = 0;
			int m; scanf("%d", &m);
			for (int j = 0; j < m; ++j) {
				int t; scanf("%d", &t); --t;
				msk |= 1 << t;
			}
			S[i].first = msk;
			scanf("%lu", &(S[i].second));
		}
		ul mx = 0;
		ul solutions[1 << (n - 1)];
		ul sol_pos = 0;
		for (ul msk = (1 << n) - 1; msk; --msk) {
			ul total = 0;
			ul mskc = msk;
			ul c;
			ul pos = 0;
			for (c = 0; mskc; mskc >>= 1) {
				c += mskc&1;
				total += mskc&1 ? t[pos] : 0;
				++pos;
			}
			if (c > k || total < mx) continue;
			for (auto &i : S) if (i.first&msk) total -= (count(i.first&msk) - 1)*i.second;
			if (total == mx) solutions[sol_pos++] = msk;
			else if (total > mx) {
				solutions[0] = msk;
				sol_pos = 1;
			}
			mx = max(mx, total);
		}
		sort(&solutions[0], solutions + sol_pos, [] (ul a, ul b) {
				while (1) {
					if ((a&1) != (b&1)) return b&1;
					a >>= 1; b >>= 1;
				}
			});
		printf("Case Number  %d\nNumber of Customers: %lu\nLocations recommended:", CASE++, mx);
		int pos = 1;
		ul best = solutions[sol_pos - 1];
		for (; best; best >>= 1) {
			if (best&1) printf(" %d", pos);
			++pos;
		}
		printf("\n\n");
	}
	return 0;
}
