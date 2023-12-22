// 0.070s/2875
#include <bits/stdc++.h>

using namespace std;

int main() {
	int s;
	int mat[101][101];
	int x, y;
	int px, py, o;
	while (scanf("%d%d%d", &x, &y, &s) && (x || y || s)) {
		for (int i = 0; i < x; ++i) {
			while (getchar() != '\n');
			for (int j = 0; j < y; ++j) {
			char t = getchar();
			switch (t) {
				case '.':
					mat[i][j] = 0;
					break;
				case '*':
					mat[i][j] = 1;
					break;
				case '#':
					mat[i][j] = 2;
					break;
				default:
					mat[i][j] = 0;
					px = i;
					py = j;
					switch (t) {
						case 'N':
							o = 0;
							break;
						case 'S':
							o = 2;
							break;
						case 'L':
							o = 1;
							break;
						case 'O':
							o = 3;
							break;
					}
			}
		}
		}
		int c = 0;
		while (getchar() != '\n');
		while (s--) {
			char t; scanf("%c", &t);
			switch (t) {
				case 'D':
					o = (o + 1)%4;
					break;
				case 'E':
					o = (o - 1)%4;
					o = o == -1 ? 3 : o;
					break;
				case 'F':
					switch (o) {
						case 0:
							if (px > 0 && mat[px - 1][py] != 2) --px;
							break;
						case 1:
							if (py + 1 < y && mat[px][py + 1] != 2) ++py;
							break;
						case 2:
							if (px + 1 < x && mat[px + 1][py] != 2) ++px;
							break;
						case 3:
							if (py > 0 && mat[px][py - 1] != 2) --py;
							break;
					}
					if (mat[px][py] == 1) {
						++c;
						mat[px][py] = 0;
					}
					break;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}
