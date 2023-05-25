// 0.000s/1600
#include <bits/stdc++.h>
#define vi vector<int>
#define ull unsigned long long

using namespace std;

ull test(ull v) {
	ull c;
	c =  ((v & 0xfff) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	c += (((v & 0xfff000) >> 12) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	c += ((v >> 24) * 0x1001001001001ULL & 0x84210842108421ULL) % 0x1f;
	return c;
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) > 0) {
		getchar();
		char c;
		int y = 0;
		ull mska = 0, mskb = -1, mskc = 0;
		while ((c = getchar()) != '\n') {
			mska |= 1 << (c - 'A');
		}
		ull msks[26] = {0};
		mskc = mska;
		queue<char> q;
		for (int i = 0; i < m; ++i) {
			char A = getchar() - 'A', B = getchar() - 'A';
			msks[A] |= 1 << B;
			msks[B] |= 1 << A;
			if (!(mska&(1 << B)) && !(mskc&(1 << B))) q.push(B);
			if (!(mska&(1 << A)) && !(mskc&(1 << A))) q.push(A);
			mskc |= 1 << A;
			mskc |= 1 << B;
			getchar();
		}
		if (n > test(mskc)) mskb = mska;
		while (!q.empty() && mska - mskb) {
			++y;
			queue<char> qq;
			for (int i = q.size(); i > 0; --i) {
				char c = q.front(); q.pop();
				if (test(msks[c]&mska) >= 3) qq.push(c);
				else q.push(c);
			}
			mskb = mska;
			while (!qq.empty()) {
				char c = qq.front(); qq.pop();
				mska |= 1 << c;
				for (int i = 0; i < 26; ++i) if (msks[c]&(1 << i)) msks[i] |= 1 << c;
			}
		}
		if (q.empty() && mska != mskb) printf("WAKE UP IN, %d, YEARS\n", y);
		else printf("THIS BRAIN NEVER WAKES UP\n");
	}
	return 0;
}
