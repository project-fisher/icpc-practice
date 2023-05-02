// 0.030s/297(1)
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		if (i) cout << '\n';
		long b, sg, sb;
		cin >> b >> sg >> sb;
		short data;
		priority_queue<short> greens;
		priority_queue<short> blues;
		while (sg--) {
			cin >> data;
			greens.push(data);
		}
		while (sb--) {
			cin >> data;
			blues.push(data);
		}
		while (!(greens.empty() || blues.empty())) {
			vector<pair<int, int>> later;
			for (int j = 0; j < b && !(greens.empty() || blues.empty()); ++j) {
				later.push_back(make_pair(greens.top(), blues.top()));
				greens.pop();
				blues.pop();
			}
			for (const auto &j : later) {
				data = j.first - j.second;
				if (data > 0) greens.push(data);
				else if (data < 0) blues.push(-data);
			}
		}
		if (greens.empty() && blues.empty()) cout << "green and blue died\n";
		else if (greens.empty()) {
			cout << "blue wins\n";
			while (!blues.empty()) {
				cout << blues.top() << '\n';
				blues.pop();
			}
		} else {
			cout << "green wins\n";
			while (!greens.empty()) {
				cout << greens.top() << '\n';
				greens.pop();
			}
		}
	}
	return 0;
}
