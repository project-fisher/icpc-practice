#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<long> x(n); for (int i = 0; i < n; ++i) scanf("%ld", &x[i]);
	set<long> l, posp;
	int np = n - 1;
	for (int i = 0; i < np; ++i) {
		posp.insert(x[i]);
		if (x[i] + 1 != x[i + 1]) l.insert(x[i] + 1);
	}
	l.insert(x.back() + 1);
	posp.insert(x.back());
	int q; scanf("%d", &q);
	while (q--) {
		int f; scanf("%d", &f); --f;
		long pos = x[f];
		long closest = *l.lower_bound(pos);
		printf("%ld\n", closest);
		l.insert(pos);
		l.erase(closest);
		long temp = *posp.lower_bound(closest + 1);
		if (temp != closest + 1) l.insert(closest + 1);
		posp.erase(pos);
		posp.insert(closest);
		x[f] = closest;
	}
	return 0;
}

