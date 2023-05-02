// 0.000s/1315(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, d, e, temp;
	cin >> a >> b >> c >> d >> e;
	while (a) {
		temp = max(a, max(b, c));
		if (temp == b) {
			temp = a;
			a = b;
			b = temp;
		} else if (temp == c) {
			temp = a;
			a = c;
			c = temp;
		}
		if (c > b) {
			temp = b;
			b = c;
			c = temp;
		}
		if (e > d) {
			temp = d;
			d = e;
			e = temp;
		}
		if (e > a) temp = 1;
		else if (d <= a && e <= b) temp = -1;
		else if (d <= a) temp = b + 1;
		else if (e < b) temp = a + 1;
		else if (e < a) temp = b + 1;
		else temp = c + 1;
		while (temp == a || temp == b || temp == c || temp == e || temp == d) temp++;
		if (temp > 52) temp = -1;
		cout << temp << '\n';
		cin >> a >> b >> c >> d >> e;
	}
}
