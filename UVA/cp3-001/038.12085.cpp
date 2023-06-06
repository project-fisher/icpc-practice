// 0.040s/183
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int id = 1, n;
	cin >> n;
	while (n) {
		cout << "Case " << id << ":\n";
		id++;
		vector<long int> data;
		data.reserve(n);
		long int t;
		while (n--) {
			cin >> t;
			data.emplace_back(t);
		}
		int prev = data[0];
		string beg = to_string(data[0]);
		int l = 0;
		for (int i = 1; i < data.size(); i++) {
			if (data[i] - prev == 1) {
				prev = data[i];
				l++;
			} else {
				cout << '0' << beg;
				if (l) {
					cout << '-';
					string pp = to_string(prev);
					int i = 0;
					while (pp[i] == beg[i]) i++;
					for (; i < pp.size(); i++) cout << pp[i];
				}
				cout << '\n';
				prev = data[i];
				beg = to_string(data[i]);
				l = 0;
			}
		}
		cout << '0' << beg;
		if (l) {
			cout << '-';
			string pp = to_string(prev);
			int i = 0;
			while (pp[i] == beg[i]) i++;
			for (; i < pp.size(); i++) cout << pp[i];
		}
		cout << '\n';
		cout << '\n';
		cin >> n;
	}
}
