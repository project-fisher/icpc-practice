// 0.010s/2909
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int p; scanf("%d", &p);
		vector<int> ps(p);
		for (int i = 0; i < p; ++i) scanf("%d", &ps[i]);
		bool ans = 0;
		for (unsigned long msk = (1 << p) - 1; !ans && msk + 1; --msk) {
			int total = 0;
			int pos = 0;
			for (unsigned long mskp = msk; mskp; mskp >>= 1) {
				total += mskp&1 ? ps[pos] : 0;
				++pos;
			}
			ans = total == n;
		}
		printf(ans ? "YES\n" : "NO\n");
	}
	return 0;
}
