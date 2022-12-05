#include <bits/stdc++.h>

using namespace std;

int solv(int a, int b, int c, int d) {
	unsigned int smallest = (unsigned int)-1, tt = 0, mx = 0, temp;
	while (c--) {
		cin >> temp;
		for (int i = 0; i < d; i++) {
			cin >> tt;
			mx = max(tt, mx);
		}
		temp *= a;
		if (mx >= a && temp < smallest && temp <= b) smallest = temp;
	}
	return (int)smallest;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, d, r;
	while (cin >> a >> b >> c >> d) {
		r = solv(a, b, c, d);
		if (r < 0) cout << "stay home";
		else cout << r;
		cout << '\n';
	}
}
