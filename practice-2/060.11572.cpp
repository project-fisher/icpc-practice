#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		int l;
		cin >> l;
		long greatest = 0;
		long current_begin = 0;
		long long id;
		map<long long, long> last;
		long pos = 0;
		while (l--) {
			cin >> id;
			if (last.count(id) && last[id] >= current_begin) {
				greatest = max(greatest, pos - current_begin);
				current_begin = last[id] + 1;
			}
			last[id] = pos;
			++pos;
		}
		greatest = max(greatest, pos - current_begin);
		cout << greatest << '\n';
	}
	return 0;
}
