#include <bits/stdc++.h>

using namespace std;

int x, y;

void solv(int a, int b) {
	if (a == x || b == y) {
		cout << "divisa";
		return;
	}
	if (a > x) {
		if (b > y) {
			cout << "NE";
			return;
		}
		cout << "SE";
		return;
	}
	if (b > y) {
		cout << "NO";
		return;
	}
	cout << "SO";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n;
	while (n) {
		cin >> x >> y;
		while (n--) {
			cin >> a >> b;
			solv(a, b);
			cout << '\n';
		}
		cin >> n;
	}
}
