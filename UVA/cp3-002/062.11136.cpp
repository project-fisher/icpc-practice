// 0.380s/266(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	while (cin >> n && n) {
		unsigned long long total = 0;
		unsigned long data;
		map<unsigned long, int> pq;
		while (n--) {
			cin >> k;
			while (k--) {
				cin >> data;
				pq[data]++;
			}
			total += (*(pq.rbegin())).first - (*(pq.begin())).first;
			if (!pq.empty()) {
				(*(pq.begin())).second--;
				if (!(*(pq.begin())).second) pq.erase(pq.begin());
			}
			if (!pq.empty()) {
				(*(pq.rbegin())).second--;
				if (!(*(pq.rbegin())).second) {
					auto it = pq.end();
					--it;
					pq.erase(it);
				}
			}
		}
		cout << total << '\n';
	}
	return 0;
}
