// 0.000s/1756(1)
#include <bits/stdc++.h>

using namespace std;

int k;
int posx[11] = {0}, posy[11] = {0};
int mem[11][1 << 11] = {0};
bool mems[11][1 << 11] = {0};

int tsp(int pos, int msk) {
	if (msk + 1 == 1 << (k + 1)) return abs(posx[0] - posx[pos]) + abs(posy[0] - posy[pos]);
	if (mems[pos][msk]) return mem[pos][msk];
	int mn = INT_MAX;
	for (int i = 0; i <= k; ++i) {
		if (msk&(1 << i)) continue;
		mn = min(mn, tsp(i, msk|(1 << i)) + abs(posx[i] - posx[pos]) + abs(posy[i] - posy[pos]));
	}
	mems[pos][msk] = 1;
	return mem[pos][msk] = mn;
}

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d%d%d", &k, &k, &posx[0], &posy[0], &k);
		for (int i = 1; i <= k; ++i) scanf("%d%d", &posx[i], &posy[i]);
		memset(mem, 0, sizeof(mem));
		memset(mems, 0, sizeof(mems));
		printf("The shortest path has length %d\n", tsp(0, 1));
	}
	return 0;
}
