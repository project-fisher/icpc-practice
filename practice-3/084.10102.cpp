// 0.020s/1198
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		vector<pair<int, int>> o;
		vector<pair<int, int>> t;
		for (int i = 0; i < n; ++i) {
			getchar();
			for (int j = 0; j < n; ++j) {
				char c = getchar();
				if (c == '1') o.push_back(make_pair(i, j));
				else if (c == '3') t.push_back(make_pair(i, j));
			}
		}
		int mx = 0;
		for (const auto &i : o) {
			int mn = 4*n;
			for (const auto &j : t) mn = min(mn, abs(i.first - j.first) + abs(i.second - j.second));
			mx = max(mn, mx);
		}
		printf("%d\n", mx);
	}
	return 0;
}

