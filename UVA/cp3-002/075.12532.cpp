// 0.210s/1787
#include <bits/stdc++.h>
#define l long
#define vl vector<long>

using namespace std;

class ST {
	private: vl mult, begin, end; vector<l> data;
		void build(l node, l start, l size) {
			begin[node] = start;
			end[node] = start + size - 1;
			if (size == 1) mult[node] = data[start];
			else {
				l size2 = size >> 1;
				build(2*node, start, size2);
				build(2*node + 1, start + size2, size - size2);
				mult[node] = mult[2*node]*mult[2*node + 1];
			}
		}

		void update(l node, l point, l value) {
			if (begin[node] == end[node]) {
				if (begin[node] == point) mult[node] = value;
			} else if (begin[node] <= point && point <= end[node]) {
				update(2*node, point, value);
				update(2*node + 1, point, value);
				mult[node] = mult[2*node]*mult[2*node + 1];
			}
		}

		l rmq(l node, l L, l R) {
			if (L <= begin[node] && end[node] <= R) return mult[node];
			if ((L <= begin[node] && begin[node] <= R) || (begin[node] <= L && L <= end[node])) return rmq(2*node, L, R)*rmq(2*node + 1, L, R);
			return 1;
		}

	public:
		ST(vector<l> &datap, l sz) {
			l log = 0, szz = sz;
			while (szz >>= 1) ++log;
			l size = 4 << log;

			data = datap;

			mult.resize(size + 1);
			begin.resize(size + 1);
			end.resize(size + 1);

			build(1, 0, sz);
		}

		void update(l point, l value) {update(1, point, value);}

		l rmq(l L, l R) {return rmq(1, L, R);}
};

int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) == 2) {
		vector<l> data(n);
		for (int i = 0; i < n; ++i) {
			l temp; scanf("%ld", &temp);
			data[i] = temp ? (temp > 0 ? 1 : -1) : 0;
		}
		ST tree(data, n);
		while (k--) {
			getchar();
			char c = getchar(); l A, B; scanf("%ld%ld", &A, &B);
			if (c == 'C') tree.update(A - 1, B ? (B > 0 ? 1 : -1) : 0);
			else printf("%c", (A = tree.rmq(A - 1, B - 1)) ? (A > 0 ? '+' : '-') : '0');
		}
		printf("\n");
	}
	return 0;
}
