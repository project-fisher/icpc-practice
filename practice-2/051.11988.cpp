#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string in;
	while (cin >> in) {
		list<list<char>> data;
		data.push_back({});
		auto it = prev(data.end());
		for (auto &c : in) {
			if (c == '[') {
				data.push_front({});
				it = data.begin();
			} else if (c == ']') {
				data.push_back({});
				it = prev(data.end());
			} else (*it).push_back(c);
		}
		for (auto &l : data) for (auto &c : l) cout << c;
		cout << '\n';
	}
	return 0;
}
