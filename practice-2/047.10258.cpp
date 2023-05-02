// 0.000s/3214
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	string in;
	getline(cin, in);
	getline(cin, in);
	for (int i = 0; i < t; ++i) {
		if (i) cout << '\n';
		long error[101][10] = {0};
		int used[101] = {0};
		vector<tuple<short, short, long>> results;
		short mapping[101] = {0};
		short a, b, c;
		char d;
		struct {
			bool operator()(const tuple<short, short, long> &v1, const tuple<short, short, long> &v2) const {return get<1>(v1) > get<1>(v2) || (get<1>(v1) == get<1>(v2) && get<2>(v1) < get<2>(v2)) || (get<1>(v1) == get<1>(v2) && get<2>(v1) == get<2>(v2) && get<0>(v1) < get<0>(v2));}
		} compa;
		while (getline(cin, in) && in.size()) {
			stringstream ss(in);
			ss >> a >> b >> c >> d;
			if (!mapping[a]) {
				mapping[a] = results.size() + 1;
				results.emplace_back(make_tuple(a, 0, 0));
			}
			if (d == 'C' && !(used[a]&(1 << b))) {
				used[a] |= (1 << b);
				get<1>(results[mapping[a] - 1])++;
				get<2>(results[mapping[a] - 1]) += c + error[a][b];
			} else if (d == 'I') error[a][b] += 20;
		}
		sort(results.begin(), results.end(), compa);
		for (auto v : results) cout << get<0>(v) << ' ' << get<1>(v) << ' ' << get<2>(v) << '\n';
	}
	return 0;
}
