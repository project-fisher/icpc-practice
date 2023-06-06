#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string k;
	cin >> k;
	n = 0;
	int has = 0;
	for (const auto &i : k) {
		if (i - '0') {
			has = 2;
			++n;
		} else if (has) {
			--has;
			++n;
		}
	}
	cout << n << '\n';
	return 0;
}
