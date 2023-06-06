// 0.000s/1787(1)
#include <bits/stdc++.h>

using namespace std;

unsigned long count(unsigned long v) {
	unsigned long c;
	for (c = 0; v; ++c) v &= v - 1;
	return c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string in;
	int n = 1;
	while (cin >> in && in != "end") {
		unsigned long msk = 0;
		for (auto &i : in) {
			i -= 'A';
			if (!(msk&(1 << i))) {
				char best = i;
				for (char j = i + 1; j < 26; ++j) if (msk&(1 << j)) {
					best = j;
					break;
				}
				msk &= ~(1 << best);
				msk |= 1 << i;
			}
		}
		cout << "Case " << n << ": " << count(msk) << '\n';
		++n;
	}
	return 0;
}
