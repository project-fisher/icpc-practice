#include <bits/stdc++.h>

using namespace std;

long double process(string &f) {
	long double angle = 0.0l;
	long double sides[88];
	sides['N'] = 0.0l;
	sides['E'] = 90.0l;
	sides['S'] = 180.0l;
	sides['W'] = 270.0l;
	angle += sides[f.back()];
	if (f.size() == 1) return angle;
	long double partition = 45.0l;
	char bback = f[f.size() - 2];
	sides['N'] = 1.0l;
	sides['E'] = 1.0l;
	sides['S'] = 1.0l;
	sides['W'] = 1.0l;
	if (bback == 'S' && f.back() == 'E') sides['E'] = -1.0l;
	else if (bback == 'S' && f.back() == 'W') sides['S'] = -1.0l;
	else if (f.back() == 'E') sides['N'] = -1.0l;
	else sides['W'] = -1.0l;
	for (int i = f.size() - 2; i >= 0; --i, partition /= 2) angle += sides[f[i]]*partition;
	return angle;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string x, y;
	cin >> x >> y;
	long double ax = process(x), ay = process(y);
	cout << setprecision(19) << min(abs(ax - ay - 360), min(abs(ax - ay), abs(ax - ay + 360))) << '\n';
	return 0;
}
