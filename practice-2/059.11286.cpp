// 0.030s/226
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n && n) {
		map<unsigned long long, int> counts;
		while (n--) {
			vector<short> courses(5);
			for (int i = 0; i < 5; ++i) cin >> courses[i];
			sort(courses.begin(), courses.end());
			unsigned long long rep = 0;
			for (int i = 0; i < 5; ++i) {
				rep *= 1000;
				rep += courses[i];
			}
			counts[rep]++;
		}
		vector<int> occs;
		for (const auto &i : counts) occs.push_back(i.second);
		sort(occs.begin(), occs.end());
		long last = occs.back();
		for (int i = occs.size() - 2; i >= 0 && occs[i] == occs.back(); --i) last += occs.back();
		cout << last << '\n';
	}
	return 0;
}
