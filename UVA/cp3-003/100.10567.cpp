// 0.050s/960
#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<long, long> &a, const long b) {
	return a.first < b;
}

int main() {
	char c;
	vector<pair<long, long>> a[123];
	vector<long> s[123];
	long pos = 1;
	char cc = getchar();
	long spos = 0;
	while ((c = getchar()) != '\n') {
		if (c != cc) {
			a[cc].push_back(make_pair(spos, pos - spos));
			if (s[cc].empty()) s[cc].push_back(0);
			s[cc].push_back(pos - spos + s[cc].back());
			cc = c;
			spos = pos;
		}
		++pos;
	}
	a[cc].push_back(make_pair(spos, pos - spos));
	if (s[cc].empty()) s[cc].push_back(0);
	s[cc].push_back(pos - spos + s[cc].back());
	int q; scanf("%d", &q);
	getchar();
	while (q--) {
		vector<pair<char, long>> b;
		cc = getchar();
		pos = 1;
		spos = 0;
		while ((c = getchar()) != '\n' && c != -1) {
			if (c != cc) {
				b.push_back(make_pair(cc, pos - spos));
				cc = c;
				spos = pos;
			}
			++pos;
		}
		b.push_back(make_pair(cc, pos - spos));
		long start = 0;
		long end = 0;
		long pos = 0;
		bool p = 1;
		auto it = distance(a[b[0].first].begin(), lower_bound(a[b[0].first].begin(), a[b[0].first].end(), pos, comp));
		if (it == a[b[0].first].size()) p = 0;
		else {
			auto it2 = distance(s[b[0].first].begin(), lower_bound(s[b[0].first].begin(), s[b[0].first].end(), s[b[0].first][it] + b[0].second));
			if (it2 == s[b[0].first].size()) p = 0;
			else {
				end = (pos = a[b[0].first][it2 - 1].first + a[b[0].first][it2 - 1].second) - s[b[0].first][it2] + s[b[0].first][it] + b[0].second - 1;
				start = a[b[0].first][it].first;
			}
		}
		for (long i = 1; i < b.size() && p; ++i) {
			it = distance(a[b[i].first].begin(), lower_bound(a[b[i].first].begin(), a[b[i].first].end(), pos, comp));
			if (it == a[b[i].first].size()) p = 0;
			else {
				auto it2 = distance(s[b[i].first].begin(), lower_bound(s[b[i].first].begin(), s[b[i].first].end(), s[b[i].first][it] + b[i].second));
				if (it2 == s[b[i].first].size()) p = 0;
				else end = (pos = a[b[i].first][it2 - 1].first + a[b[i].first][it2 - 1].second) - s[b[i].first][it2] + s[b[i].first][it] + b[i].second - 1;
			}
		}
		if (p) printf("Matched %ld %ld\n", start, end);
		else printf("Not matched\n");

	}
	return 0;
}
