// 0.440s/3150
#include <bits/stdc++.h>
#define vl vector<long>
using namespace std;

class ST {
	private: vl st, A;
		long n;
		long left(long p) {return p << 1;}
		long right(long p) {return left(p) + 1;}
		void build(long p, long L, long R) {
			if (L == R) st[p] = L;
			else {
				build(left(p), L, (L + R) >> 1);
				build(right(p), ((L + R) >> 1) + 1, R);
				long p1 = st[left(p)], p2 = st[right(p)];
				st[p] = (A[p1] > A[p2]) ? p1 : p2;
			}
		}
		long rmq(long p, long L, long R, long i, long j) {
			if (i > R || j < L || i > j) return -1;
			if (L >= i && R <= j) return st[p];
			long p1 = rmq(left(p), L, (L + R) >> 1, i, j);
			long p2 = rmq(right(p), ((L + R) >> 1) + 1, R, i, j);
			if (p1 == -1) return p2;
			if (p2 == -1) return p1;
			return (A[p1] > A[p2]) ? p1 : p2;
		}
	public:
		ST(const vl &Ap) {
			A = Ap;
			n = (long)A.size();
			st.assign(4*n, 0);
			build(1, 0, n - 1);
		}
		long rmq(long i, long j) {return rmq(1, 0, n - 1, i, j);}
};

int main() {
	long n, q;
	while (scanf("%ld%ld", &n, &q) == 2) {
		vector<long> d(n);
		for (long i = 0; i < n; ++i) scanf("%ld", &d[i]);
		map<long, long> freq;
		map<long, long> start;
		for (long i = 0; i < n; ++i) {
			freq[d[i]]++;
			if (!start.count(d[i])) start[d[i]] = i;
		}
		vector<long> appear(n);
		vector<long> begin(n);
		for (long i = 0; i < n; ++i) {
			appear[i] = freq[d[i]];
			begin[i] = start[d[i]];
		}
		ST t(appear);
		while (q--) {
			long l, r, k; scanf("%ld%ld", &l, &r);
			--l; --r;
			if (d[l] == d[r]) printf("%ld\n", r - l + 1);
			else printf("%ld\n", max(appear[l] + begin[l] - l, max((k = t.rmq(appear[l] + begin[l], begin[r] - 1)) > -1 ? appear[k] : 0, r - begin[r] + 1)));
		}
	}
	return 0;
}
