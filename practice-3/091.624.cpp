// 0.610s/8353(1)
#include <bits/stdc++.h>

using namespace std;


int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		int t; scanf("%d", &t);
		vector<int> ts(t);
		for (int i = 0; i < t; ++i) scanf("%d", &ts[i]);
		int mxt = 0;
		int mxc = 0;
		int mskr;
		for (unsigned long msk = (1 << t) - 1; msk; --msk) {
			int total = 0;
			int c = 0;
			int pos = 0;
			for (unsigned long mskp = msk; mskp; mskp >>= 1) {
				c += mskp&1;
				total += mskp&1 ? ts[pos] : 0;
				++pos;
			}
			if (total > n) continue;
			if (mxt < total) {
				mxt = total;
				mskr = msk;
				mxc = c;
			} else if (mxt == total && c > mxc) {
				mxc = c;
				mskr = msk;
				mxt = total;
			}
		}
		int pos = 0;
		for (; mskr; mskr >>= 1) {
			if (mskr&1) printf("%d ", ts[pos]);
			++pos;
		}
		printf("sum:%d\n", mxt);
	}
	return 0;
}
