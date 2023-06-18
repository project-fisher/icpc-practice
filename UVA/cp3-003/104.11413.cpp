// 0.000s/1866
#include <bits/stdc++.h>

using namespace std;
vector<long> a;

bool fits_into(long mid, long m) {
	int taken = 0;
	long s = 0;
	for (auto &i : a) { 
		if (i + s <= mid) s += i;
		else {
			s = i;
			++taken;
		}
	}
	++taken;
	return taken <= m;
}

int main() {
	long n, m;
	while (scanf("%ld%ld", &n, &m) == 2) {
		a.resize(n);
		for (int i = 0; i < n; ++i) scanf("%ld", &a[i]);
		long inf = *max_element(a.begin(), a.end()), sup = accumulate(a.begin(), a.end(), 0);
		long mid = (inf + sup) >> 1;
		long best = sup;
		while (inf <= sup) {
			if (fits_into(mid, m)) {
				sup = mid - 1;
				best = min(best, mid);
			} else inf = mid + 1;
			mid = (inf + sup) >> 1;
		}
		printf("%ld\n", best);
	}
	return 0;
}
