// 0.000s/>10K(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	short n;
	short i = 1;
	int a, b, c;
	unsigned char k, l, m;
	cin >> n;
	while (i <= n) {
		cin >> a >> b >> c;
		k = b > c;
		l = a > b;
		m = a > c;
		cout << "Case " << i++ << ": " << (m && !l || !(m || !l) ? a : 0) + (k && l || !(k || l) ? b : 0) + (m && !k || !(m || !k) ? c : 0) << '\n';
	}
}
