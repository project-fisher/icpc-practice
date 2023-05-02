#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
	unordered_map<int, long> ks;
	string reg;
	int id, n;
	long per;
	while (cin >> reg && reg[0] != '#') {
		cin >> id >> per;
		pq.push(make_pair(per, id));
		ks[id] = per;
	}
	cin >> n;
	while (n--) {
		cout << pq.top().second << '\n';
		auto temp = pq.top();
		pq.pop();
		temp.first += ks[temp.second];
		pq.push(temp);
	}
	return 0;
}
