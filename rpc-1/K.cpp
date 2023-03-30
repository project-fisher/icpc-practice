#include <bits/stdc++.h>

using namespace std;

long int dist(long int x1, long int x2, long int y1, long int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	int a;
	long int b, c;
	cin >> a;
	map<long int, pair<long int, long int>> d;
	vector<long int> d1;
	map<long int, pair<long int, long int>> d2;
	while (a--) {
		cin >> b >> c;
		if (d.count(b)) {
			d[b].second = max(d[b].second, c);
			d[b].first = min(d[b].first, c);
		} else {
			d1.insert(upper_bound( d1.begin(), d1.end(), b), b);
			d[b] = {c, c};
			d2[b] = {0, 0};
		}
	}
	if (d1.size() == 0) {
		cout << 0 << '\n';
		return 0;
	}
	long int p = dist(0, 0, d[d1.back()].first, d[d1.back()].second);
	if (d1.size() == 1) {
		cout << p << '\n';
		return 0;
	}
	d2[d1.back()].first = p;
	d2[d1.back()].second = p;
	for (int i = d1.size() - 2; i >= 0; i--) {
		d2[d1[i]].second = min(d2[d1[i + 1]].first + dist(d1[i], d1[i + 1], d[d1[i]].first, d[d1[i + 1]].first), d2[d1[i + 1]].second + dist(d1[i], d1[i + 1], d[d1[i]].first, d[d1[i + 1]].second));
		if (d[d1[i]].first == d[d1[i]].second) {
			d2[d1[i]].first = d2[d1[i]].second;
		} else {
			d2[d1[i]].first = min(d2[d1[i + 1]].first + dist(d1[i], d1[i + 1], d[d1[i]].second, d[d1[i + 1]].first), d2[d1[i + 1]].second + dist(d1[i], d1[i + 1], d[d1[i]].second, d[d1[i + 1]].second));
			p = dist(0, 0, d[d1[i]].first, d[d1[i]].second);
			d2[d1[i]].first += p;
			d2[d1[i]].second += p;
		}
	}
	cout << min(d2[d1[0]].first, d2[d1[0]].second) << '\n';
	return 0;
}
