#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long n, q; string s; cin >> n >> q >> s;
	long offset = 0;
	while (q--) {
		char t; long x; cin >> t >> x;
		if (t == '1') {
			offset -= x;
			offset += offset < 0 ? n : 0;
		} else cout << s[(offset + x - 1)%n] << '\n';
	}

	return 0;
}
