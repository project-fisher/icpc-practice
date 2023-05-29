#include <bits/stdc++.h>

using namespace std;

class ST {
	private: vector<int> rm, begin, end; int mx;
	void build(int node, int start, int size) {
		begin[node] = start;
		end[node] = start + size - 1;
		if (size == 1) rm[node] = 0;
		else {
			int size2 = size >> 1;
			build(2*node, start, size2);
			build(2*node + 1, start + size2, size - size2);
			rm[node] = 0;
		}
	}
	void update(int node, int L, int R, int value) {
		if (L <= begin[node] && end[node] <= R) rm[node] = value;
		else if ((L <= begin[node] && begin[node] <= R) || (begin[node] <= L && L <= end[node])) {
			update(2*node, L, R, value);
			update(2*node + 1, L, R, value);
			rm[node] = max(rm[2*node], rm[2*node + 1]);
		}
	}
	int get(int node, int L, int R) {
		if (L <= begin[node] && end[node] <= R) return rm[node];
		if ((L <= begin[node] && begin[node] <= R) || (begin[node] <= L && L <= end[node])) return max(get(2*node, L, R), get(2*node + 1, L, R));
		return 0;
	}
	public:
	ST(int size) {
		int log = 1, sz = size;
		while (sz >>= 1) ++log;
		sz = 3 << log;
		++sz;
		rm.resize(sz);
		begin.resize(sz);
		end.resize(sz);
		mx = size;
		build(1, 0, size);
	}
	void update(int L, int R, int value) {update(1, L, R, value);}
	int rmq(int L, int R) {
		if (L <= R) return get(1, L, R);
		return max(get(1, L, mx - 1), get(1, 0, R));
	}
};

int main() {
	int n, q; scanf("%d%d", &n, &q);
	ST tree(n);
	while (q--) {
		char buffer[2]; scanf("%s", buffer);
		if (buffer[0] == '?') {
			int x, y; scanf("%d%d", &x, &y); --x; --y;
			printf(min(tree.rmq(x, y), tree.rmq(y, x)) ? "impossible\n" : "possible\n");
		} else {
			int x; scanf("%d", &x); --x;
			tree.update(x, x, buffer[0] == '-');
		}
	}
	return 0;
}
