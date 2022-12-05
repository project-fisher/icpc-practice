#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, mx;
	char c;
	cin >> n;
	while (n--) {
		cin >> c >> a >> b;
		mx = 0;
		switch (c) {
			case 'K':
				mx = ((a >> 1) + (a&1))*((b >> 1) + (b&1));
				break;
			case 'Q':
				mx = min(a, b);
				break;
			case 'r':
				mx = min(a, b);
				break;
			case 'k':
				mx = ((a*b) >> 1) + (a&b&1);
		}
		cout << mx << '\n';
	}
}
