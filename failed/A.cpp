#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a, b, c, d;
	cin >> a >> b;
	b *= -1;
	int ok = 0;
	if (a == 11 && b == 11) ok = 1;
	int pos = 2;
	bool sw;
	while (--n && !ok) {
		cin >> c >> d;
		d *= -1;
		if (!(c == a && d == b)) {
			sw = !((a + b)&1);
			if (a == 11 || b == 11) {
				ok = pos;
			} else if (c == a + 1 && d == b && !sw) {
			} else if (c == b + 1 && d == a && sw) {
			} else if (c == a && d == b + 1 && !sw) {
			} else if (c == b && d == a + 1 && sw) {
			} else {
				ok = pos;
			}
		}
		a = c; b = d;
		++pos;
	}
	if (!ok) cout << "ok\n";
	else cout << "error " << ok << '\n';
	return 0;
}
