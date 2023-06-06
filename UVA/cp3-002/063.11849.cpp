// 1.940s/6318
// I did not realize that the input was ordered/ordering would be faster than doing whatever this is.
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long n, m, t;
	while (cin >> n && cin >> m && n|m) {
		set<long> data[2];
		++n;
		while (--n) {
			cin >> t;
			data[0].insert(t);
		}
		++m;
		while (--m) {
			cin >> t;
			data[1].insert(t);
		}
		vector<long> is;
		set_intersection(data[0].begin(), data[0].end(), data[1].begin(), data[1].end(), back_inserter(is));
		cout << is.size() << '\n';
	}
	return 0;
}
