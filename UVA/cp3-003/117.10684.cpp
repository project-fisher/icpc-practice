// 0.050s/2867(2)
// Had to resubmit because I didn't put the period mark at the end of the losing streak message.
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		vector<int> a(n); for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		long mx = *max_element(a.begin(), a.end()), sum = 0;
		for (auto &i : a) {
			sum += i;
			mx = max(mx, sum);
			sum = max(sum, 0l);
		}
		if (mx <= 0) printf("Losing streak.\n");
		else printf("The maximum winning streak is %ld.\n", mx);
	}
	return 0;
}
