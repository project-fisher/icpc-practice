// 0.050s/125
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	char data;
	short score;
	data = getchar();
	while (data != 'G') {
		vector<short> v;
		data = (data == 'X' || data == '/') ? ':' : data;
		v.push_back(data - '0');
		data = getchar();
		while (data == ' ') {
			data = getchar();
			data *= data != 'X' && data != '/' ? 1 : 0;
			data += !data ? ':' : 0;
			v.push_back(data - '0');
			data = getchar();
		}
		score = 0;
		int i = 0, j = 0;
		while (i < v.size()) {
			j++;
			if (v[i] < 10) {
				if (v[i + 1] < 10) {
					score += v[i];
					score += v[i + 1];
				} else {
					score += 10;
					score += v[i + 2];
					if (j == 10) break;
				}
				i++;
			} else {
				score += 10;
				if (v[i + 1] != 10 && v[i + 2] == 10) {
					score += 10;
				} else {
					score += v[i + 1];
					score += v[i + 2];
				}
				if (j == 10) break;
			}
			i++;
		}
		cout << score << '\n';
		data = getchar();
	}
	return 0;
}
