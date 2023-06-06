// 0.000s/1892(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int c; scanf("%d", &c);
	while (c--) {
		int n; scanf("%d", &n);
		vector<int> poli(n + 1);
		for (int i = 0; i <= n; ++i) scanf("%d", &poli[i]);
		long d, k; scanf("%ld%ld", &d, &k);
		long pos = 0;
		n = 0;
		while (pos < k) pos += d*(++n);
		unsigned long long a = 0, pown = 1;
		for (auto &i : poli) {
			a += i*pown;
			pown *= n;
		}
		printf("%llu\n", a);
	}
	return 0;
}
