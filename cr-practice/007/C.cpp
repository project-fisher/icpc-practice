#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<llu> a(n); for (int i = 0; i < n; ++i) scanf("%llu", &a[i]);
	vector<llu> ap = a;
	sort(ap.begin(), ap.end());
	auto last = unique(ap.begin(), ap.end());
	ap.erase(last, ap.end());
	int k[200002] = {0};
	for (int i = 0; i < n; ++i) {
		++k[ap.size() - (lower_bound(ap.begin(), ap.end(), a[i]) - ap.begin() + 1)];
	}
	for (int i = 0; i < n; ++i) printf("%d\n", k[i]);
	return 0;
}
