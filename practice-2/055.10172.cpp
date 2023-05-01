#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int sets;
	cin >> sets;
	while (sets--) {
		int n, s, q, qi, tqi, total = 0, pos = 0, time = 0;
		cin >> n >> s >> q;
		stack<int> carrier;
		queue<int> stations[n];
		for (int i = 0; i < n; ++i) {
			cin >> qi;
			while (qi--) {
				cin >> tqi;
				++total;
				stations[i].push(tqi);
			} 
		}
		do {

			while (!carrier.empty() && (stations[pos].size() < q || carrier.top() == pos + 1)) {
				if (carrier.top() != pos + 1) stations[pos].push(carrier.top());
				else --total;
				carrier.pop();
				++time;
			}
			while (carrier.size() < s && !stations[pos].empty()) {
				carrier.push(stations[pos].front());
				stations[pos].pop();
				++time;
			}
			time += 2;
			pos = (pos + 1)%n;
		} while (total);
		time -= 2;
		cout << time << '\n';
	}
	return 0;
}
