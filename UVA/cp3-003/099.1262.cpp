// 0.010s/798
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int k;
		unsigned long msk[5] = {0}, mskp[5] = {0};
		char buffer[6] = {0};
		scanf("%d", &k);
		for (int i = 0; i < 6; ++i) {
			scanf("%s", buffer);
			for (int j = 0; j < 5; ++j) msk[j] |= 1 << (buffer[j] - 'A');
		}
		for (int i = 0; i < 6; ++i) {
			scanf("%s", buffer);
			for (int j = 0; j < 5; ++j) mskp[j] |= 1 << (buffer[j] - 'A');
		}
		for (int i = 0; i < 5; ++i) msk[i] &= mskp[i];
		vector<string> ans;
		unsigned long t1, t2, t3, t4;
		for (char a = 'A'; msk[0]; ++a, msk[0] >>= 1) if (msk[0]&1) {t1 = msk[1];
		for (char b = 'A'; t1; ++b, t1 >>= 1) if (t1&1) {t2 = msk[2];
		for (char c = 'A'; t2; ++c, t2 >>= 1) if (t2&1) {t3 = msk[3];
		for (char d = 'A'; t3; ++d, t3 >>= 1) if (t3&1) {t4 = msk[4];
		for (char e = 'A'; t4; ++e, t4 >>= 1) if (t4&1) {
			string temp = {a, b, c, d, e};
			ans.push_back(temp);
		}}}}}
		if (k <= ans.size()) printf("%s\n", ans[k - 1].c_str());
		else printf("NO\n");
	}

	return 0;
}
