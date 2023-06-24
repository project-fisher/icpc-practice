#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<map<char, int>> m;
	while (n--) {
		char buffer[31];
		scanf("%s", buffer);
		for (int i = 0; buffer[i]; ++i) {
			if (i == m.size()) m.push_back({});
			m[i][buffer[i]]++;
		}
	}
	int k = 0;
	for (auto &i : m) {
		vector<pair<int, char>> d;
		for (auto &j : i) d.push_back(make_pair(j.second, j.first));
		sort(d.begin(), d.end());
		int mx = d.back().first;
		printf("%d:", ++k);
		for (auto &j : d) if (j.first == mx) printf(" %c", j.second);
		printf("\n");
	}
	return 0;
}

		
