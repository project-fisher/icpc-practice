#include <bits/stdc++.h>

using namespace std;

double MAX(double a, double b) {
	return (a + b + (a > b ? a - b : b - a))/2;
}

int solv(int a, int b, int c, int d) {
	int cnt = 0;
	double u = (double)b;
	double pos = 0;
	double l = u*d/100.0;
	while (pos <= a && pos >= 0) {
		pos += u;
		cnt++;
		if (pos > a) break;
		pos -= c;
		u -= l;
		u = MAX(u, 0);
	}
	return cnt*(-1 + 2*(pos >= a));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, d, r;
	cin >> a >> b >> c >> d;
	while (a) {
		r = solv(a, b, c, d);
		if (r < 0) cout << "failure on day " << r*-1;
		else cout << "success on day " << r;
		cout << '\n';
		cin >> a >> b >> c >> d;
	}
}
