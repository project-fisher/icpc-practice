// 4.650s/1947(1)
// used https://www.redgreencode.com/solving-uva-11402-with-segment-trees/
// This has got to be the most devilish problem I've done so far...
#include <bits/stdc++.h>
#define l long
#define vl vector<long>

using namespace std;

class ST {
	private: vl sum, begin, end; vector<char> laze; bitset<1048575> data;
		void build(l node, l start, l size) {
			begin[node] = start;
			end[node] = start + size - 1;
			if (size == 1) sum[node] = data[start];
			else {
				l size2 = size >> 1;
				build(2*node, start, size2);
				build(2*node + 1, start + size2, size - size2);
				sum[node] = sum[2*node] + sum[2*node + 1];
			}
		}

		char relate_flip(char state) {
			switch (state) {
				case 1: return 2;
				case 2: return 1;
				case 3: return 0;
			}
			return 3;
		}

		void change(l node, char state) {
			switch (state) {
				case 1: sum[node] = 0;
					break;
				case 2: sum[node] = end[node] - begin[node] + 1;
					break;
				case 3: sum[node] = end[node] - begin[node] + 1 - sum[node];
					break;
			}
			if (begin[node] != end[node]) {
				if (state != 3) laze[2*node] = laze[2*node + 1] = state;
				else {
					laze[2*node] = relate_flip(laze[2*node]);
					laze[2*node + 1] = relate_flip(laze[2*node + 1]);
				}
			}
		}
		
		void prop(l node) {
			if (!laze[node]) return;
			change(node, laze[node]);
			laze[node] = 0;
		}

		void update(l node, l L, l R, char state) {
			prop(node);
			if (L <= begin[node] && end[node] <= R) return change(node, state);
			if ((L <= begin[node] && begin[node] <= R) || (begin[node] <= L && L <= end[node])) {
				update(2*node, L, R, state);
				update(2*node + 1, L, R, state);
				sum[node] = sum[2*node] + sum[2*node + 1];
			}
		}

		l rsq(l node, l L, l R) {
			if (begin[node] <= L && R <= end[node]) {
				if (laze[node] == 1) return 0;
				else if (laze[node] == 2) return R - L + 1;
			}
			if (L <= begin[node] && end[node] <= R) {
				prop(node);
				return sum[node];
			}
			if ((L <= begin[node] && begin[node] <= R) || (begin[node] <= L && L <= end[node])) {
				prop(node);
				return rsq(2*node, L, R) + rsq(2*node + 1, L, R);
			}
			return 0;
		}

	public:
		ST(bitset<1048575> &datap, l sz) {
			l log = 0, szz = sz;
			while (szz >>= 1) ++log;
			l size = 4 << log;

			data = datap;

			sum.resize(size + 1);
			begin.resize(size + 1);
			end.resize(size + 1);
			laze.assign(size + 1, 0);

			build(1, 0, sz);
		}

		void update(l L, l R, char state) {update(1, L, R, state);}

		l rsq(l L, l R) {return rsq(1, L, R);}
};

int main() {
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		bitset<1048575> pirates;
		pirates.reset();
		l m; scanf("%ld", &m);
		l pos = 0;
		while (m--) {
			l T; scanf("%ld", &T);
			char buffer[51]; scanf("%s", buffer);
			for (int i = 0; i < T; ++i) for (int j = 0; buffer[j]; ++pos, ++j) if (buffer[j] - '0') pirates.set(pos);
		}
		l q; scanf("%ld", &q);
		ST tree(pirates, pos);
		l qs = 0;
		printf("Case %d:\n", i + 1);
		while (q--) {
			char c[2]; l L, R; scanf("%s%ld%ld", c, &L, &R);
			switch (c[0]) {
				case 'F':
					tree.update(L, R, 2);
					break;
				case 'E':
					tree.update(L, R, 1);
					break;
				case 'I':
					tree.update(L, R, 3);
					break;
				case 'S':
					printf("Q%ld: %ld\n", ++qs, tree.rsq(L, R));
					break;
			}
		}
	}
	return 0;
}
