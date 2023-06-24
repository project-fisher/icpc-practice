#include <bits/stdc++.h>

using namespace std;

#define llu unsigned long long

int main() {
	int n, k; scanf("%d%d", &n, &k);
	llu mx = 1llu << n, cnt = 0llu;
	for (llu msk = 0llu; msk < mx; ++msk) {
		int prev = 2;
		int ln = 0;
		llu mskp = msk|mx;
		for (; mskp != 1llu; mskp >>= 1llu) {
			if (prev != (mskp&1)) {
				ln = 1;
				prev = mskp&1;
			} else {
				if (ln == k) break;
				++ln;
			}
		}
		cnt += mskp == 1;
	}
	printf("%llu\n", cnt);
	return 0;
}


