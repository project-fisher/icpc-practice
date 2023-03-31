#include <bits/stdc++.h>

using namespace std;

struct CmpI {
	int asas(const pair<int, int> &g) const {
		return g.first;
	}

	int asas(int g) const {
		return g;
	}

	template<typename T1, typename T2>
	bool operator()(T1 const &t1, T2 const &t2) const { 
		return asas(t1) < asas(t2);
	}
};
struct CmpS {
	int asas(const pair<int, int> &g) const {
		return g.second;
	}

	int asas(int g) const {
		return g;
	}

	template<typename T1, typename T2>
	bool operator()(T1 const &t1, T2 const &t2) const { 
		return asas(t1) < asas(t2);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c, d, e;
	cin >> a >> b;
	while (a|b) {
		vector<pair<int, int>> v = {{-1, -1}, {100002, 100002}};
		while (b--) {
			cin >> c >> d;
			int i_t = 0;
			int j_t = 0;
			int i = distance(v.begin(), lower_bound(v.begin(), v.end(), c, CmpI()));
			int j = distance(v.begin(), lower_bound(v.begin(), v.end(), d, CmpS()));
			//while (v[++i].second < c);
			//while (v[++j].second < d);
			if (i && v[i - 1].second + 1 == c) c = v[--i].first;
			else if (i_t = (v[i].first - 1 <= c)) c = v[i].first - (v[i].first - 1 == c);
			if (j_t = (v[j].first - 1 <= d)) d = v[j].second + (v[j].second + 1 == d);
			//cout << v[i].first << ' ' << v[i].second << '\n';
			//cout << "c: " << c << " d: " << d << '\n'; 
			if (i == j && !i_t && !j_t) {
				pair<int, int> p = {c, d};
				v.insert(next(v.begin(), i), p);
			} else {
				//for (int k = i; k < j - 1 + j_t; ++k)
				v.erase(next(v.begin(), i), next(v.begin(), j - 1 + j_t));
				v[i].first = c;
				v[i].second = d;
			}
			int rmn = v[i].first - 1, rmx = v[i].second + 1;
			if (rmn) cout << rmn;
			else cout << '*';
			cout << ' ';
			if (a >= rmx) cout << rmx;
			else cout << '*';
			cout << '\n';
			//for (auto &f : v) cout << f.first << ':' << f.second << ' ';
			//cout << '\n';
		}
		cout << "-\n";
		cin >> a >> b;
	}
	return 0;
}
