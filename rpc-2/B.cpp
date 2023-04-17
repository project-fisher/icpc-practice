#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	long double n, x, y, beg, rat, ratt, tar, ttar;
	cin >> n;
	cin >> beg >> y;
	cin >> x >> y;
	rat = y/(x - beg);
	stack<pair<long double, long double>> rev;
	rev.push({x, y});
	while (cin >> x >> y) {
		if ((ratt = y/(x - beg)) > rat) rat = ratt;
		rev.push({x, y});
	}
	pair<long double, long double> xy = rev.top(); rev.pop();
	beg = xy.first;
	xy = rev.top(); rev.pop();
	tar = xy.second/(beg - xy.first);
	n -= 3;
	while (n--) {
		xy = rev.top(); rev.pop();
		if ((ttar = xy.second/(beg - xy.first)) > tar) tar = ttar;
	}
	cout << setprecision(19) << atanl(max(rat, tar))*180.0/3.141592653589793238463 << '\n';
	return 0;
}
