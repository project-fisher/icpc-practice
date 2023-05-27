// 0.060s/3267
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	int c = 0;
	while (scanf("%d", &n) == 1 && n) {
		printf("Case %d:\n", ++c);
		vector<int> data;
		vector<int> s;
		for (int i = 0; i < n; ++i) {
			int k; scanf("%d", &k);
			for (auto j : data) s.emplace_back(j + k);
			data.emplace_back(k);
		}
		sort(s.begin(), s.end());
		int m; scanf("%d", &m);
		while (m--) {
			int k; scanf("%d", &k);
			printf("Closest sum to %d is ", k);
			int pos = distance(s.begin(), lower_bound(s.begin(), s.end(), k));
			if (pos == 0) k = s[pos];
			else if (pos == s.size()) k = s[pos - 1];
			else if (abs(s[pos - 1] - k) < abs(s[pos] - k)) k = s[pos - 1];
			else k = s[pos];
			printf("%d.\n", k);
		}
	}
	return 0;
}
