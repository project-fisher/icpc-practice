// 0.000s/1116
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	unsigned int c;
	cin >> c;
	while (c--) {
		unsigned int l, m, total = 0;
		cin >> l >> m;
		l *= 100;
		queue<unsigned int> cars[2];
		while (m--) {
			unsigned int cm;
			string side;
			cin >> cm >> side;
			cars[side == "right"].push(cm);
		}
		bool side = 0;
		while (!(cars[0].empty() && cars[1].empty())) {
			unsigned int collect = 0;
			while (!cars[side].empty() && cars[side].front() + collect <= l) {
				collect += cars[side].front();
				cars[side].pop();
			}
			++total;
			side = !side;
		}
		cout << total << '\n';
	}
	return 0;
}
