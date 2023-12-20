#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n, k; scanf("%d%d", &n, &k);
	queue<int> d; for (int i = 0; i < n; ++i) {
		int dd; scanf("%d", &dd);
		d.push(dd);
	}
	lu mx = 1;
	lu time = 0;
	multiset<lu> s;
	for (int i = 0; i < min(n, k); ++i) {
		s.insert(d.front());
		d.pop();
	}
	while (s.size()) {
		int pend = s.count(*s.begin());
		mx = max(mx, *s.begin() - time);
		time = *s.begin();
		s.erase(*s.begin());
		for (int i = 0; i < pend && d.size(); ++i) {
			s.insert(time + d.front());
			d.pop();
		}
	}
	printf("%lu\n", mx);
	return 0;
}
