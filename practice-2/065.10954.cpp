#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long t;
	while (cin >> n && n) {
		priority_queue<long, vector<long>, greater<long>> pq;
		while (n--) {
			cin >> t;
			pq.push(t);
		}
		long cost = 0;
		while (pq.size() > 1) {
			t = pq.top();
			pq.pop();
			t += pq.top();
			pq.pop();
			cost += t;
			pq.push(t);
		}
		cout << cost << '\n';
	}
	return 0;
}
