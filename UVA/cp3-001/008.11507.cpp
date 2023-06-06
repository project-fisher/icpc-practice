// 0.010s/1013(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string text;
	cin >> n;
	int i = 0;
	while (n) {
		i++;
		char x = 1, y = 0, z = 0;
		while (--n) {
			cin >> text;
			if (text == "-y") {
				if (y) {x = y; y = 0;}
				else if (x) {y = -x; x = 0;}
			} else if (text == "+y") {
				if (y) {x = -y; y = 0;}
				else if (x) {y = x; x = 0;}
			} else if (text == "-z") {
				if (z) {x = z; z = 0;}
				else if (x) {z = -x; x = 0;}
			} else if (text == "+z") {
				if (z) {x = -z; z = 0;}
				else if (x) {z = x; x = 0;}
			}
		}
		if (x == 1) cout << "+x";
		else if (x == -1) cout << "-x";
		else if (y == 1) cout << "+y";
		else if (y == -1) cout << "-y";
		else if (z == 1) cout << "+z";
		else cout << "-z";
		cout << '\n';
		cin >> n;
	}
}
