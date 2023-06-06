#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first ? 1 : (a.first > b.first ? 0 : (a.second >= b.second ? 1 : 0));
}

int main() {
	int n, x, y, z; scanf("%d%d%d%d", &n, &x, &y, &z);
	vector<pair<int, int>> a(n);
	vector<pair<int, int>> b(n);
	vector<pair<int, int>> s(n);
	for (int i = 0; i < n; ++i) {
		int ai; scanf("%d", &ai);
		s[i] = {ai, i};
		a[i] = {ai, i};
	}
	for (int i = 0; i < n; ++i) {
		int bi; scanf("%d", &bi);
		s[i].first += bi;
		b[i] = {bi, i};
	}
	sort(a.begin(), a.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	sort(s.begin(), s.end(), cmp);
	bitset<1000> marked = 0;
	int c = 0;
	for (int i = n - 1; c < x; --i) {
		marked.set(a[i].second);
		++c;
	}
	c = 0;
	for (int i = n - 1; c < y; --i) {
		if (!marked[b[i].second]) {
			marked.set(b[i].second);
			++c;
		}
	}
	c = 0;
	for (int i = n - 1; c < z; --i) {
		if (!marked[s[i].second]) {
			++c;
			marked.set(s[i].second);
		}
	}
	for (int i = 0; i < n; ++i) if (marked[i]) printf("%d\n", i + 1);
	return 0;
}
