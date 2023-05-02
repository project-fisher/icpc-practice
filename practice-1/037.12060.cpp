// 0.000s/666
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
	int c;
	while ((c = a%b)) {
		a = b;
		b = c;
	} 
	return b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int id = 1;
	cin >> n;
	while (n) {
		int c = 0;
		int t;
		for (int i = 0; i < n; i++) {
			cin >> t;
			c += t;
		}
		int g = gcd(abs(c), n);
		c /= g;
		n /= g;
		int f = c/n;
		c %= n;
		int tc = c, tf = f;
		c = abs(c);
		f = abs(f);
		cout << "Case " << id << ":\n";
		if (c) {
			int lc, ln, lf, extra, mx;
			lc = (c >= 1000000000) ? 9 : (c >= 100000000) ? 8 : (c >= 10000000) ? 7 : 
				(c >= 1000000) ? 6 : (c >= 100000) ? 5 : (c >= 10000) ? 4 : 
				(c >= 1000) ? 3 : (c >= 100) ? 2 : (c >= 10) ? 1 : 0;
			ln = (n >= 1000000000) ? 9 : (n >= 100000000) ? 8 : (n >= 10000000) ? 7 : 
				(n >= 1000000) ? 6 : (n >= 100000) ? 5 : (n >= 10000) ? 4 : 
				(n >= 1000) ? 3 : (n >= 100) ? 2 : (n >= 10) ? 1 : 0;
			lf = (f >= 1000000000) ? 9 : (f >= 100000000) ? 8 : (f >= 10000000) ? 7 : 
				(f >= 1000000) ? 6 : (f >= 100000) ? 5 : (f >= 10000) ? 4 : 
				(f >= 1000) ? 3 : (f >= 100) ? 2 : (f >= 10) ? 1 : 0;
			lc++;
			ln++;
			lf++;
			lf -= f == 0;
			mx = max(lc, ln);
			extra = (tf < 0 || tc < 0)*2 + lf + mx;
			cout << right << setw(extra) << fixed << c << '\n';
			if (tf < 0 || tc < 0) cout << "- ";
			if (f) cout << f;
			while (mx--) cout << '-';
			cout << '\n';
			cout << right << setw(extra) << fixed << n;
		} else if (tf > 0) {
			cout << f;
		} else if (f) {
			cout << "- " << f;
		} else {
			cout << '0';
		}
		cout << '\n';
		id++;
		cin >> n;
	}
}
