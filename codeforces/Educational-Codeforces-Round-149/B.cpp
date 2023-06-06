#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long n; cin >> n;
		string s; cin >> s;
		int inc = 1, mxinc = 0;
		char prev = 0;
		for (auto &i : s) {
			if (i == prev) ++inc;
			else {
				mxinc = max(mxinc, inc);
				inc = 1;
			}
			prev = i;
		}
		mxinc = max(mxinc, inc) + 1;
		cout << mxinc << '\n';
	}
	return 0;
}
