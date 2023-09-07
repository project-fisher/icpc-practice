#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	map<int, set<vector<long>>> data;
	while (n--) {
		int m; scanf("%d", &m);
		vector<pair<int, int>> points(m);
		while (m--) {
			int x, y; scanf("%d%d", &x, &y);
			points[m].first = x;
			points[m].second = y;
		}
		sort(points.begin(), points.end());
		int tx = -points.front().first, ty = -points.front().second;
		vector<long> temp = {0};
		for (int i = 1; i < points.size(); ++i) temp.push_back((points[i].first + tx)*10000 + points[i].second + ty);
		if (!data.count(points.size())) data[points.size()] = {};
		data[points.size()].insert(temp);
	}
	int total = 0;
	for (auto &i : data) total += i.second.size();
	printf("%d\n", total);
	return 0;
}

