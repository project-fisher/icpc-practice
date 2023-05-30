// 0.000s/2752
#include <bits/stdc++.h>

using namespace std;

int t, n, c, a, pos;
pair<int, int> buffer[12];
int ans[12];

void backtrack(int i, int sum) {
	if (sum == t) {
		printf("%d", ans[0]);
		for (i = 1; i < a; ++i) printf("+%d", ans[i]);
		printf("\n");
		++c;
		return;
	}
	if (sum > t || i == n) return;
	for (int k = 0; k < buffer[i].second; ++k) ans[a++] = buffer[i].first;
	for (int j = buffer[i].second; j >= 0; --j) {
		backtrack(i + 1, sum + buffer[i].first*j);
		--a;
	}
	++a;
}

int main() {
	while (scanf("%d%d", &t, &n) == 2 && t) {
		printf("Sums of %d:\n", t);
		int temp; scanf("%d", &temp);
		buffer[0] = {temp, 1};
		int pos = 0;
		for (int i = 1; i < n; ++i) {
			scanf("%d", &temp);
			if (temp == buffer[pos].first) buffer[pos].second++;
			else {
				++pos;
				buffer[pos] = {temp, 1};
			}
		}
		n = pos + 1;
		c = 0;
		a = 0;
		backtrack(0, 0);
		if (!c) printf("NONE\n");
	}
	return 0;
}
