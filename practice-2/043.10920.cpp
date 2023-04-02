#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long int a, b, c, n, w, side, offset, x, y;

	while (cin >> a >> b && a|b) {
		a >>= 1;
		if (b != 1) {
			c = (long long int)sqrt(b - 1);
			n = (c >> 1) + (c&1);
			w = b - 2 - (n > 1 ? (n*(n - 1)) << 2 : 0);
			side = w/(n << 1);
			offset = w - side*(n << 1) + 1;
			x = side&1 ? n : n - offset;
			y = side&1 ? n - offset : n;
			x *= side == 1 || side == 2 ? -1 : 1;
			y *= side == 2 || side == 3 ? -1 : 1;
		} else x = y = 0;
		x += ++a;
		y += a;
		cout << "Line = " << y << ", column = " << x << ".\n";
	}

	return 0;
}
