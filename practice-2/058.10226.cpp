// 0.330s/754
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string data;
		if (i) cout << '\n';
		else {
			getline(cin, data);
			getline(cin, data);
		}
		map<string, int> counts;
		int total = 0;
		getline(cin, data);
		while (!data.empty()) {
			counts[data]++;
			getline(cin, data);
			++total;
		}
		vector<string> keys;
		for (auto const &imap : counts) keys.push_back(imap.first);
		sort(keys.begin(), keys.end());
		for (const auto &i : keys) cout << i << ' ' << fixed << setprecision(4) << ((long double)(100.0l*counts[i]/total)) << '\n';
		counts.clear();
		total = 0;
	}
	return 0;
}
