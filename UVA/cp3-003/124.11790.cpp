// 0.040s/1042
#include <bits/stdc++.h>
#define llu unsigned long long

using namespace std;

int main() {
	int t; scanf("%d", &t);
	for (int T = 1; T <= t; ++T) {
		int n; scanf("%d", &n);
		vector<llu> h(n), w(n);
		for (int i = 0; i < n; ++i) scanf("%llu", &h[i]);
		for (int i = 0; i < n; ++i) scanf("%llu", &w[i]);
		vector<llu> li, ld;
		for (int i = 0; i < n; ++i) {
			llu mxi = 0, mxd = 0;
			for (int j = 0; j < i; ++j) {
				if (h[i] > h[j]) mxi = max(mxi, li[j]);
				if (h[i] < h[j]) mxd = max(mxd, ld[j]);
			}
			li.push_back(mxi + w[i]);
			ld.push_back(mxd + w[i]);
		}
		llu mxi = *max_element(li.begin(), li.end()), mxd = *max_element(ld.begin(), ld.end());
		if (mxi >= mxd) printf("Case %d. Increasing (%llu). Decreasing (%llu).\n", T, mxi, mxd);
		else printf("Case %d. Decreasing (%llu). Increasing (%llu).\n", T, mxd, mxi);
	}
	return 0;
}
