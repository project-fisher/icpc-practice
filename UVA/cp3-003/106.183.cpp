// 0.000s/749
#include <bits/stdc++.h>

using namespace std;
int r, c;
int pos, p;
char data[40001];
char ans[401][401];
map<tuple<int, int, int, int>, char> memo;

void show_b(int rw, int cl, int x, int y) {
	if (!rw || !cl) return;
	tuple<int, int, int, int> t = {rw, cl, x, y};
	printf("%c", memo[t]);
	if (++p == 50) {
		printf("\n");
		p = 0;
	}
	if (memo[t] == 'D') {
		int hrw = rw >> 1, hcl = cl >> 1;
		show_b(rw - hrw, cl - hcl, x, y);
		show_b(rw - hrw, hcl, x, y + cl - hcl);
		show_b(hrw, cl - hcl, x + rw - hrw, y);
		show_b(hrw, hcl, x + rw - hrw, y + cl - hcl);
	}
}

char create_b(int rw, int cl, int x, int y) {
	if (!rw || !cl) return 0;
	tuple<int, int, int, int> tup = {rw, cl, x, y};
	if (rw == 1 && cl == 1) {
		memo[tup] = data[x*c + y];
		return data[x*c + y];
	}
	int hrw = rw >> 1, hcl = cl >> 1;
	char t, c = 0;
	if (t = create_b(rw - hrw, cl - hcl, x, y)) c = c && c != t ? 'D' : t;
	if (t = create_b(rw - hrw, hcl, x, y + cl - hcl)) c = c && c != t ? 'D' : t;
	if (t = create_b(hrw, cl - hcl, x + rw - hrw, y)) c = c && c != t ? 'D' : t;
	if (t = create_b(hrw, hcl, x + rw - hrw, y + cl - hcl)) c = c && c != t ? 'D' : t;
	memo[tup] = c;
	return c;
}

void create_d(int rw, int cl, int x, int y) {
	if (!rw || !cl) return;
	if (data[pos] != 'D') {
		int rwx = rw + x, cly = cl + y;
		for (int i = x; i < rwx; ++i) for (int j = y; j < cly; ++j) ans[i][j] = data[pos];
		++pos;
		return;
	}
	++pos;
	int hrw = rw >> 1, hcl = cl >> 1;
	create_d(rw - hrw, cl - hcl, x, y);
	create_d(rw - hrw, hcl, x, y + cl - hcl);
	create_d(hrw, cl - hcl, x + rw - hrw, y);
	create_d(hrw, hcl, x + rw - hrw, y + cl - hcl);
}

int main() {
	char next_char = getchar();
	while (next_char != '#') {
		scanf("%d%d", &r, &c);
		while (getchar() != '\n');
		pos = 0;
		char ch;
		while ((ch = getchar()) != '#' && ch != 'B' && ch != ' ' && ch != -1) {
			if (ch == '\n') continue;
			data[pos++] = ch;
		}
		pos = 0;
		p = 0;
		memo = {};
		if (next_char == 'B') {
			printf("D%4d%4d\n", r, c);
			create_b(r, c, 0, 0);
			show_b(r, c, 0, 0);
		} else {
			printf("B%4d%4d\n", r, c);
			create_d(r, c, 0, 0);
			for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
				printf("%c", ans[i][j]);
				if (++p == 50) {
					printf("\n");
					p = 0;
				}
			}
		}
		if (p) printf("\n");
		next_char = ch == ' ' ? 'D' : ch;
	}
	return 0;
}
