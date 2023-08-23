// 0.010s/1010(1)
// wtf??
#include <bits/stdc++.h>
#define ll long long

using namespace std;

/*vector<ll> lis(vector<ll> &a) {
	if (a.empty()) return {};
	vector<ll> l = {a.front()};
	vector<int> pos(a.size());
	pos[0] = 1;
	for (int i = 1; i < a.size(); ++i) {
		if (a[i] > l.back()) {
			l.push_back(a[i]);
			pos[i] = l.size();
		} else {
			auto it = lower_bound(l.begin(), l.end(), a[i]); 
			pos[i] = it - l.begin() + 1;
			*it = a[i];
		}
	}
	vector<ll> ans(l.size());
	for (int i = a.size() - 1, x = l.size(); i >= 0; --i) if (pos[i] == x) ans[--x] = a[i];
	return ans;
}*/

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<ll> c(n); for (int i = 0; i < n; ++i) scanf("%lld", &c[i]);
		vector<int> lis(n);
		vector<int> lds(n);
		int mx = 0;
		for (int i = c.size() - 1; i >= 0; --i) {
			lis[i] = 1;
			lds[i] = 1;
			for (int j = i + 1; j < c.size(); ++j) {
				if (c[j] < c[i]) lis[i] = max(lis[i], lis[j] + 1);
				if (c[j] > c[i]) lds[i] = max(lds[i], lds[j] + 1);
			}
			mx = max(mx, lis[i] + lds[i] - 1);
		}
		printf("%d\n", mx); 
	}
	return 0;
}

