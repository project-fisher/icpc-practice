// 0.000s/383(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, mx, o, g;
	cin >> a >> b;
	while (a || b) {
		o = a;
		g = b;
		if (a < b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}
		if (a >= 3 && b >= 3) mx =  ((a*b) >> 1) + (a&b&1);
		else if (!b) mx = 0;
		else if (b == 1) mx = a;
		else if (a == 2 || a == 3) mx = 4;
		else if (a&1) mx = a + 1;
		else if (a&3) mx = a + 2;
		else mx = a;
		cout << mx << " knights may be placed on a " << o << " row " << g << " column board." << '\n';
		cin >> a >> b;
	}
}
