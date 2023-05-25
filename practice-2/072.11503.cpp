// 0.760s/2332
#include <bits/stdc++.h>
#define vl vector<long>

using namespace std;

class UF {
	private: vl rank, p, cnt;
	public:
		UF(long n) {
			rank.assign(n, 0);
			cnt.assign(n, 1);
			p.resize(n);
			iota(p.begin(), p.end(), 0);
		}

		long find(long i) {
			return (p[i] == i) ? i : (p[i] = find(p[i]));
		}

		long sizeSet(long i) {
			return cnt[find(i)];
		}

		void unite(long i, long j) {
			if ((i = find(i)) != (j = find(j))) {
				if (rank[i] > rank[j]) {
					p[j] = p[i];
					cnt[i] += cnt[j];
					cnt[j] = 0;
				} else {
					p[i] = p[j];
					cnt[j] += cnt[i];
					cnt[i] = 0;
					if (rank[i] == rank[j]) ++rank[j];
				}
			}
		}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) {
		long n; cin >> n;
		UF u(100001);
		long c = 0;
		map<string, long> m;
		while (n--) {
			string a, b; cin >> a >> b;
			if (!m.count(a)) m[a] = c++;
			if (!m.count(b)) m[b] = c++;
			u.unite(m[a], m[b]);
			cout << u.sizeSet(m[a]) << '\n';
		}
	}
	return 0;
}
