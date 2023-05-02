// 0.000s/5165
#include <bits/stdc++.h>

using namespace std;

bool comparator(string &a, string &b) {
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input, other;
	map<string, int> cnt;
	map<string, string> mirror;
	vector<string> data;
	cin >> input;
	while (input[0] != '#') {
		data.push_back(input);
		other = input;
		transform(other.cbegin(), other.cend(),
                	other.begin(),
                	[](unsigned char c) {return toupper(c);});
		sort(other.begin(), other.end());
		mirror[input] = other;
		++cnt[other];
		cin >> input;
	}
	sort(data.begin(), data.end(), comparator);
	for (const auto &i : data) if (cnt[mirror[i]] == 1) cout << i << '\n';
	return 0;
}
