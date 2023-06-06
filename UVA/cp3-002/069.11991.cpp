// 0.050s/729
#include <bits/stdc++.h>

using namespace std;

int main() {
	long n, q;
	while (scanf("%ld%ld", &n, &q) > 0) {
		map<long, vector<long>> m;
		for (int i = 1; i <= n; ++i) {
			long v; scanf("%ld", &v);
			m[v].push_back(i);
		}
		while (q--) {
			long k, v; scanf("%ld%ld", &k, &v);
			if (!m.count(v) || k > m[v].size()) printf("0\n");
			else printf("%ld\n", m[v][k - 1]);
		}
	}
}
