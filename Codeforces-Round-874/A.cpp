#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		set<string> data;
		string k = {s[0], s[1]};
		data.insert(k);
		int r = 1;
		for (int i = 2; i < s.size(); ++i) {
			k = {s[i - 1], s[i]};
			if (!data.count(k)) {
				data.insert(k);
				++r;
			}
		}
		cout << r << '\n';
	}
	return 0;
}
