#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long
using namespace std;

int main() {
	int H, W; scanf("%d%d", &H, &W);
	char r[1001];
	int rr[1001] = {0};
	while (H--) {
		scanf("%s", r);
		for (int i = 0; r[i]; ++i) rr[i] += r[i] == '#';
	}
	for (int i = 0; r[i]; ++i) {
		if (i) printf(" ");
		printf("%d", rr[i]);
	}
	puts("");
	return 0;
}
