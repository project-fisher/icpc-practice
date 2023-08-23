// 0.020s/1689(1)
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	vector<ll> a;
	ll n;
	while (scanf("%lld", &n) == 1) a.push_back(n);
	vector<ll> L;
	vector<stack<int>> Lp;
	for (int i = 0; i < a.size(); ++i) {
		if (!L.size() || a[i] > L.back()) {
			L.push_back(a[i]);
			Lp.push_back({});
			Lp.back().push(i);
		} else {
			int it = distance(L.begin(), lower_bound(L.begin(), L.end(), a[i]));
			L[it] = a[i];
			Lp[it].push(i);
		}
	}
	printf("%lu\n-\n", L.size());
	vector<ll> LIS;
	int last = Lp.back().top();
	LIS.push_back(a[last]);
	for (int i = L.size() - 2; i >= 0; --i) {
		while (Lp[i].top() > last) Lp[i].pop();
		last = Lp[i].top();
		LIS.push_back(a[last]);
	}
	for (int i = L.size() - 1; i >= 0; --i) printf("%lld\n", LIS[i]);
	return 0;
}






