#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long n;
	cin >> n;
	long mx = 0;
	long beg = 0;
	long cur, prev, peak;
	--n;
	cin >> beg;
	prev = beg;
	bool up = true;
	while (n--) {
		cin >> cur;
		if (cur < prev && up) {
			up = 0;
			peak = prev;
		} else if (!up && cur > prev) {
			up = 1;
			mx = max(mx, peak - max(beg, prev));
			//cout << beg << ' ' << peak << ' ' << prev << '\n';
			beg = prev;
		}
		prev = cur;
	}
	if (!up) mx = max(mx, peak - max(beg, prev));
	cout << mx << '\n';
	return 0;
}
