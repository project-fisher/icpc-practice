// 0.020s/978(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	bool nl = 0;
	while (scanf("%d", &n) == 1 && n) {
		if (nl) printf("\n");
		nl = 1;
		map<long, int> a;
		for (int i = 0; i < n; ++i) {
			long t; scanf("%ld", &t);
			a[t]++;
		}	
		int mx = 0;
		for (auto &i : a) mx = max(mx, i.second);
		printf("%d\n", mx);
		vector<vector<long>> ans(mx);
		while (!a.empty()) {
			for (int i = 0; i < mx && !a.empty(); ++i) {
				ans[i].push_back((*a.begin()).first);
				if (!(--(*a.begin()).second)) a.erase(a.begin());
			}
		}
		for (auto &i : ans) {
			printf("%ld", i.front());
			for (int j = 1; j < i.size(); ++j) printf(" %ld", i[j]);
			printf("\n");
		}
	}
	return 0;
}
				


		
