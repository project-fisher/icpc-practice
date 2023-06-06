// 0.000s/4519
#include <bits/stdc++.h>

using namespace std;

int solv(int a, double b, double c, int d) {
	int m = 0;
	double to_pay = c;
	double pay = c/a;
	c += b;
	pair<int, double> data[d + 1];
	for (int i = 0; i < d; i++)
		cin >> data[i].first >> data[i].second;
	data[d].first = 0;
	int i = 0;
	c *= 1 - data[i].second;
	while (to_pay >= c) {
		m++;
		if (data[i + 1].first == m) i++;
		to_pay -= pay;
		c *= 1 - data[i].second;
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, d, r;
	double b, c;
	cin >> a >> b >> c >> d;
	while (a >= 0) {
		cout << (r = solv(a, b, c, d));
		if (r == 1) cout << " month";
		else cout << " months";
		cout << '\n';
		cin >> a >> b >> c >> d;
	}
}
