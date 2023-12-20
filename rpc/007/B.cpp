#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<pair<int, pair<int, pair<int, int>>>> cu;
	for (int i = 0; i < n; ++i) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		cu.push_back(make_pair(b, make_pair(a, make_pair(c, d))));
	}
	sort(cu.begin(), cu.end());
	lu b = 0;
	for (auto &i : cu) {
		if (i.first + i.second.second.second < b) continue;
		printf("%d\n", i.second.first);
		b = max((lu)i.first, b) + i.second.second.first;
	}

	return 0;
}
