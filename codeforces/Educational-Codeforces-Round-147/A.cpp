#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, r, pos;
	cin >> t;
	string s;
	while (t--) {
		cin >> s;
		if (s.front() == '0') cout << "0\n";
		else {
			r = 1;
			pos = 10 - (s.front() == '?' ? 1 : 0);
			for (auto &i : s) {
				r *= i == '?' ? pos : 1;
				pos = 10;
			}
			cout << r << '\n';
		}
	}
	return 0;
}
