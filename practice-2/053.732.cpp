// 0.030s/203
#include <bits/stdc++.h>

using namespace std;

void backtrack(string &a, int pos_a, string &b, int pos_b, stack<char> &s,  bitset<20003> &q, int pos_q) {
	if (pos_b == b.size()) {
		cout << (q[0] ? 'i' : 'o');
		for (int i = 1; i < pos_q; ++i) cout << ' ' << (q[i] ? 'i' : 'o'); 
		cout << '\n';
		return;
	}
	if (pos_a < a.size()) {
		q[pos_q] = 1;
		s.push(a[pos_a]);
		backtrack(a, pos_a + 1, b, pos_b, s, q, pos_q + 1);
		s.pop();
	}
	if (!s.empty() && b[pos_b] == s.top()) {
		q[pos_q] = 0;
		s.pop();
		backtrack(a, pos_a, b, pos_b + 1, s, q, pos_q + 1);
		s.push(b[pos_b]);
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b, c, d;
	while (cin >> a) {
		cin >> b;
		cout << "[\n";
		c = a;
		d = b;
		sort(c.begin(), c.end());
		sort(d.begin(), d.end());
		stack<char> stk;
		bitset<20003> q;
		if (c == d) backtrack(a, 0, b, 0, stk, q, 0);
		cout << "]\n";
	}
	return 0;
} 
