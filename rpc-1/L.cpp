#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int n;
vector<unordered_map<lli, int>> d;
vector<vector<lli>> d1;
map<tuple<int, int, lli>, int> mem;

/*int money_simp(int pos, int m, int p, lli c, bool has) {
	if (pos == n) return m;
	int mx = 0;
	if (c) {
		if (d[pos].count(c) && d[pos][c] > p) mx = money_simp(pos, m + d[pos][c], 0, 0, 1);
		return max(mx, money_simp(pos + 1, m, p, c, 1));
	}
	if (has) {
		for (auto v : d1[pos]) if (m >= d[pos][v]) mx = max(mx, money_simp(pos + 1, m - d[pos][v], d[pos][v], v, 1));
		return max(mx, money_simp(pos + 1, m, p, c, 1));
	}
	for (auto v : d1[pos]) mx = max(mx, money_simp(pos + 1, -d[pos][v], d[pos][v], v, 1));
	return max(mx, money_simp(pos + 1, 0, 0, 0, 0));
}*/

int money_dp(int pos, int m, int p, lli c, bool has) {
	if (pos == n) return m;
	tuple<int, int, lli> t = {pos, m, c};
	if (mem.count(t)) return mem[t] - 1;
	int mx = 0;
	if (c) {
		if (d[pos].count(c) && d[pos][c] > p) mx = money_dp(pos, m + d[pos][c], 0, 0, 1);
		return mem[t] = max(mx, money_dp(pos + 1, m, p, c, 1));
	}
	for (auto v : d1[pos]) if (!has || m >= d[pos][v]) mx = max(mx, money_dp(pos + 1, m - d[pos][v], d[pos][v], v, 1));
	return mem[t] = max(mx, money_dp(pos + 1, m, p, c, has));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	short m;
	lli I;
	int P;
	for (int i = 0; i < n; i++) {
		cin >> m;
		d.push_back({});
		d1.push_back({});
		while (m--) {
			cin >> I >> P;
			d[i][I + 1] = P;
			d1[i].push_back(I + 1);
		}
	}
	cout << money_dp(0, 0, 0, 0, 0) << '\n';
	return 0;
}
