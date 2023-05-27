// 0.060s/1837
#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	for (int z = 0; z < t; ++z) {
		if (z) printf("\n");
		int d; scanf("%d", &d);
		char buffer[21];
		vector<pair<pair<long, long>, string>> ranges(d);
		for (int i = 0; i < d; ++i) {
			scanf("%s", buffer); string s(buffer);
			long mn, mx; scanf("%ld%ld", &mn, &mx);
			ranges[i] = {{mn, mx}, s};
		}
		sort(ranges.begin(), ranges.end());
		int q; scanf("%d", &q);
		while (q--) {
			int count = 0;
			string last;
			long p; scanf("%ld", &p);
			for (auto &i : ranges) {
				if (i.first.first > p) break;
				if (i.first.second >= p) {
					last = i.second;
					++count;
				}
			}
			if (count == 1) {
				for (auto &i : last) printf("%c", i);
				printf("\n");
			} else printf("UNDETERMINED\n");
		}
	}
	return 0;
}
