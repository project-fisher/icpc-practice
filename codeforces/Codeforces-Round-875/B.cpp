#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<pair<int, int>> a, b;
		for (int i = 0; i < n; ++i) {
			int p; scanf("%d", &p);
			if (!a.size() || a.back().first != p) a.push_back(make_pair(p, 1));
			else ++a.back().second;
		}
		for (int i = 0; i < n; ++i) {
			int p; scanf("%d", &p);
			if (!b.size() || b.back().first != p) b.push_back(make_pair(p, 1));
			else ++b.back().second;
		}
		map<int, int> ap, bp;
		int mx = 0;
		for (auto &i : a) {
			if (!ap.count(i.first)) ap[i.first] = i.second;
			else ap[i.first] = max(i.second, ap[i.first]);
			mx = max(mx, i.second);
		}
		for (auto &i : b) {
			if (!bp.count(i.first)) bp[i.first] = i.second;
			else bp[i.first] = max(i.second, bp[i.first]);
			mx = max(mx, i.second);
		}
		for (auto &i : ap) if (bp.count(i.first)) mx = max(mx, i.second + bp[i.first]);
		printf("%d\n", mx);
	}
	return 0;
}
