#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int level = 0;
	vector<pair<int, int>> place = {{0, 0}};
	int ls[100002];
	ls[0] = 0;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		level -= s[0] == '>';
		level += s[0] == '<';
		place.emplace_back(make_pair(level, i + 1));
	}
	sort(place.begin(), place.end());
	for (int i = n; i >= 0; --i) ls[place[i].second] = i + 1;
	cout << ls[0];
	for (int i = 1; i < n + 1; ++i) cout << ' ' << ls[i];
	cout << '\n';
	return 0;
}
