// 0.000s/1694
#include <bits/stdc++.h>

using namespace std;

int main() {
	int f, r;
	while (scanf("%d%d", &f, &r) == 2) {
		vector<int> F(f);
		vector<double> fr;
		for (int i = 0; i < f; ++i) scanf("%d", &F[i]);
		for (int i = 0; i < r; ++i) {
			int R; scanf("%d", &R);
			for (const auto i : F) fr.emplace_back((double)(R)/i);
		}
		sort(fr.begin(), fr.end());
		double mx = 0;
		for (int i = fr.size() - 1; i > 0; --i) mx = max(mx, fr[i]/fr[i - 1]);
		printf("%.*f\n", 2, mx);
	}
	return 0;
}
