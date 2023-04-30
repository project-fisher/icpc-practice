#include <bits/stdc++.h>

using namespace std;

int counts(vector<int> &d, int r, int l) {
	auto first = lower_bound(d.begin(), d.end(), l);
	if (first != d.end()) return distance(first, upper_bound(d.begin(), d.end(), r - 1)) + 1;
	return 0;
}

bool contiene(int l, int r, int ap[], int n, map<int, vector<int>> &c, map<int, vector<int>> &c_o) {
	set<int> seen;
	for (int i = l; i < r; ++i) {
		if (!seen.count(ap[i])) {
			if (counts(c[ap[i]], r, l) != counts(c_o[ap[i]], r, l)) return 0;
			//if (upper_bound(c[ap[i]].begin(), c[ap[i]].end(), r - 1) - lower_bound(c[ap[i]].begin(), c[ap[i]].end(), l) != upper_bound(c_o[ap[i]].begin(), c_o[ap[i]].end(), r - 1) - lower_bound(c_o[ap[i]].begin(), c_o[ap[i]].end(), l)) return 0;
			seen.insert(ap[i]);
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, l, r, prev, best = 0;
	cin >> t;
	while (t--) {
		cin >> n;
		int a[n];
		int ap[n];
		vector<pair<int, int>> d;
		map<int, vector<int>> c;
		map<int, vector<int>> c_o;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (!c.count(a[i])) c[a[i]] = {};
			c[a[i]].emplace_back(i);
		}
		for (map<int, vector<int>>::iterator i = c.begin(); i != c.end(); ++i) {
			sort(i->second.begin(), i->second.end());
		}
		for (int i = 0; i < n; ++i) {
			cin >> ap[i];
			if (!c_o.count(ap[i])) c_o[ap[i]] = {};
			c_o[ap[i]].emplace_back(i);
		}
		for (map<int, vector<int>>::iterator i = c_o.begin(); i != c_o.end(); ++i) {
			sort(i->second.begin(), i->second.end());
		}
		l = 0;
		prev = ap[0];
		for (int i = 1; i < n; ++i) {
			if (prev > ap[i]) {
				if (l != i - 1) d.push_back(make_pair(l, i));
				l = i;
			}
			prev = ap[i];
		}
		if (l != n - 1) d.push_back(make_pair(l, n));
		best = 0;
		l = 0; r = 0;
		for (const auto &i : d) {
			int result = 0;
			for (int j = i.second - i.first; j > best && !result; --j) for (int k = i.first; k + j <= i.second && !result; ++k) if (contiene(k, k + j, ap, n, c, c_o)) {
				result = j;
				l = k;
				r = k + j;
			}
			if (result) best = result;
		}
		cout << l + 1 << ' ' << r << '\n';
	}
	return 0;
}
