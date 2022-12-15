#include <bits/stdc++.h>

using namespace std;

bool comp(string &a, string &b) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == b[i]) continue;
		return toupper(a[i]) < toupper(b[i]) || (abs(a[i] - b[i]) == 32 && a[i] < b[i]);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string word;
	cin >> n;
	while (n--) {
		cin >> word;
		vector<string> data;
		sort(word.begin(), word.end());
		do 
			data.push_back(word);
		while (next_permutation(word.begin(), word.end()));
		sort(data.begin(), data.end(), comp);
		for (const auto &i : data) cout << i << '\n';
	}
	return 0;
}
