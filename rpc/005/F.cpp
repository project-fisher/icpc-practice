#include <bits/stdc++.h>

using namespace std;

#define llu unsigned long long
class ST {
	private: vector<llu> sum, begin, end, data;
	void build(long node, int start, int size) {
		begin[node] = start;
		end[node] = start + size - 1;
		if (size == 1) sum[node] = data[start];
		else {
			int size2 = size >> 1;
			build(2*node, start, size2);
			build(2*node + 1, start + size2, size - size2);
			sum[node] = sum[2*node] + sum[2*node + 1];
		}
	}
	void update(long node, int L, int R, llu inc) {
		if (L <= begin[node] && end[node] <= R) sum[node] += inc;
		else if (( L <= begin[node] && begin[node] <= R) || (begin[node] <= L && L <= end[node])) {
			update(2*node, L, R, inc);
			update(2*node + 1, L, R, inc);
			sum[node] = sum[2*node] + sum[2*node + 1];
		}
	}

	llu get(long node, int L, int R) {
		if (L <= begin[node] && end[node] <= R) return sum[node];
		else if (( L <= begin[node] && begin[node] <= R) || (begin[node] <= L && L <= end[node])) return get(2*node, L, R) + get(2*node + 1, L, R);
		return 0;
	}

	public:
	ST(vector<llu> &datap, int size) {
		long log = 1l, sz = size;
		while (sz >>= 1l) ++log;
		sz = 3l << log;
		data = datap;
		sum.resize(sz + 1l);
		begin.resize(sz + 1l);
		end.resize(sz + 1l);
		build(1l, 0, size);
	}

	void update(int P, llu inc) {
		update(1l, P, P, inc);
	}

	llu get(int L, int R) {
		return get(1l, L, R);
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<llu> data(n); for (int i = 0; i < n; ++i) scanf("%llu", &data[i]);
	ST tree(data, n);
	int q; scanf("%d", &q);
	while (q--) {
		while (getchar() != '\n');
		if (getchar() == 'R') { 
			int a, b; scanf("%d%d", &a, &b);
			printf("%llu\n", tree.get(a - 1, b - 1));
		} else {
			int a; llu b; scanf("%d%llu", &a, &b);
			tree.update(a - 1, b);
		}
	}
	return 0;
}
