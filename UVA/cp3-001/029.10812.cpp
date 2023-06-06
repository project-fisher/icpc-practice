// 0.000s/9176
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--) {
		unsigned long long int a, b, c, d;
		cin >> a >> b;
		c = (a - b) >> 1;
		d = a - c;
		if (c < d) swap(c, d);
		if (a < b || c - d != b) cout << "impossible";
		else {
			cout << c << ' ' << d;
		}
		cout << '\n';
	}
}
