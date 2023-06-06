// 0.000s/1496
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n) {
		int c = (n >> 2) + ((n&3) != 0);
		int a = 1;
		int diff = 4 - (n&3);
		if (diff == 4) diff = 0;
		cout << "Printing order for " << n << " pages:\n";
		if (n == 1) {
			cout << "Sheet 1, front: Blank, 1\n";
			cin >> n;
			continue;
		}
		n = c << 2;
		for (int i = 1; i <= c; i++) {
			cout << "Sheet " << i << ", front: ";
			if (diff) {
				diff--;
				cout << "Blank";
			} else cout << n;
			cout << ", ";
			cout << a;
			cout << '\n';
			a++;
			n--;
			cout << "Sheet " << i << ", back : ";
			cout << a;
			cout << ", ";
			if (diff) {
				diff--;
				cout << "Blank";
			} else cout << n;
			cout << '\n';
			a++;
			n--;
		}
		cin >> n;
	}
}
