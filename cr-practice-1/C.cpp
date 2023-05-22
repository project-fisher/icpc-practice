#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long data;
	cin >> n;
	bitset<2*100000 + 1> s;
	cin >> s;
	vector<long long> kids;
	vector<long long> adults;
	for (int i = 0; i < n; ++i) {
		cin >> data;
		if (s[n - i - 1]) adults.push_back(-data);
		else kids.push_back(data);
	}
	sort(kids.begin(), kids.end());
	sort(adults.begin(), adults.end());
	int best = max(kids.size(), adults.size());
	for (int i = 0; i < kids.size(); ++i) {
		best = max(best, i + 1 + (int)distance(adults.begin(), upper_bound(adults.begin(), adults.end(), -kids[i] - 1)));
	}
	cout << best << '\n';
	return 0;
}
