// 0.080s/1580(2)
#include <bits/stdc++.h>

using namespace std;
vector<long> a;

bool attempt(int k) {
	int pos = 0;
	for (auto &i : a) {
		if (abs(i - pos) > k) return 0;
		k -= abs(i - pos) == k ? 1 : 0;
		pos = i;
	}
	return 1;
}

int main() {
	int t; scanf("%d", &t);
	for (int T = 1; T <= t; ++T) {
		int n; scanf("%d", &n);
		a.resize(n); for (int i = 0; i < n; ++i) scanf("%ld", &a[i]);
		int inf = 0, sup = a.back();
		int mid = (inf + sup) >> 1, best = a.back();
		while (inf <= sup) {
			if (attempt(mid)) {
				sup = mid - 1;
				best = min(best, mid);
			}
			else inf = mid + 1;
			mid = (inf + sup) >> 1;
		}
		printf("Case %d: %d\n", T, best);
	}

	return 0;
}
