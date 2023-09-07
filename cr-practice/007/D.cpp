#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	llu H, W; scanf("%llu%llu", &H, &W);
	llu tr, tc; scanf("%llu%llu", &tr, &tc);
	int n; scanf("%d", &n);
	map<llu, set<llu>> v, h;
	while (n--) {
		llu r, c; scanf("%llu%llu", &r, &c);
		if (!v.count(r)) {
			v[r] = {};
			v[r].insert(0);
			v[r].insert(W + 1);
		}
		if (!h.count(c)) {
			h[c] = {};
			h[c].insert(0);
			h[c].insert(H + 1);
		}
		v[r].insert(c);
		h[c].insert(r);
	}
	int q; scanf("%d", &q);
	while (q--) {
		char c[2]; llu x; scanf("%s%llu", c, &x);
		switch (c[0]) {
			case 'L':
				if (v.count(tr)) {
					auto it = v[tr].lower_bound(tc);
					if (*it != tc) it = prev(it);
					tc = max(tc > x ? tc - x : 1, *it + 1);
				} else tc = tc > x ? tc - x : 1;
				break;
			case 'D':
				if (h.count(tc)) tr = min(tr + x, *h[tc].upper_bound(tr) - 1);
				else tr = min(tr + x, H);
				break;
			case 'R':
				if (v.count(tr)) tc = min(tc + x, *v[tr].upper_bound(tc) - 1);
				else tc = min(tc + x, W);
				break;
			case 'U':
				if (h.count(tc)) {
					auto it = h[tc].lower_bound(tr);
					if (*it != tr) it = prev(it);
					tr = max(tr > x ? tr - x : 1, *it + 1);
				} else tr = tr > x ? tr - x : 1;
				break;
		}
		printf("%llu %llu\n", tr, tc);
	}
	return 0;
}
