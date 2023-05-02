#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, command, v;
	while (cin >> n) {
		priority_queue<int> pq;
		stack<int> s;
		queue<int> q;
		char pqp = 1, sp = 1, qp = 1;
		while (n--) {
			cin >> command >> v;
			if (command == 1) {
				if (pqp) pq.push(v);
				if (sp) s.push(v);
				if (qp) q.push(v);
			} else {
				if (pqp) pqp = !pq.empty() && pq.top() == v;
				if (sp) sp = !s.empty() && s.top() == v;
				if (qp) qp = !q.empty() && q.front() == v;
				if (pqp) pq.pop();
				if (sp) s.pop();
				if (qp) q.pop();
			}
		}
		if (!(pqp || sp || qp)) cout << "impossible";
		else if (pqp + sp + qp - 1) cout << "not sure";
		else if (pqp) cout << "priority queue";
		else if (qp) cout << "queue";
		else cout << "stack";
		cout << '\n';
	}
	return 0;
}
