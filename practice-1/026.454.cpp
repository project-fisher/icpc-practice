#include <bits/stdc++.h>

using namespace std;

bool comp(string &a, string &b) {
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input, other;
	int n;
	cin >> n;
	getline(cin, input);
	getline(cin, input);
	for (int lk = 0; lk < n; lk++) {
		if (lk) cout << '\n';
		map<string, vector<string>> cnt;
		map<string, int> mcnt;
		map<string, string> mirror;
		vector<string> data;
		getline(cin, input);
		while (input.size()) {
			data.push_back(input);
			other = input;
			other.erase(remove(other.begin(), other.end(), ' '), other.end());
			sort(other.begin(), other.end());
			mirror[input] = other;
			if (cnt.count(other)) cnt[other].push_back(input);
			else {
				cnt[other] = vector<string>();
				cnt[other].push_back(input);
			}
			++mcnt[input];
			getline(cin, input);
		}
		sort(data.begin(), data.end(), comp);
		for (const auto &i : data) if (cnt[mirror[i]].size() > 1) {
			sort(cnt[mirror[i]].begin(), cnt[mirror[i]].end(), comp);
			--mcnt[i];
			int t = mcnt[i];
			for (int j = 0; j < cnt[mirror[i]].size(); j++) {
				if (i < cnt[mirror[i]][j]) cout << i << " = " << cnt[mirror[i]][j] << '\n';
				if (i == cnt[mirror[i]][j]) {
					for (int k = 0; k < t; k++) cout << i << " = " << i << '\n';
					t = 0;
				}
			}
		}
	}
	return 0;
}
