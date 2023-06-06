// 0.000s/4364
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k = 0;
	while (scanf("%d", &n) && n) {
		if (k++) printf("\n");
		vector<int> s(n);
		for (int i = 0; i < n; ++i) scanf("%d", &s[i]);
		for (int a = 0; a < n; ++a)
			for (int b = a + 1; b < n; ++b)
				for (int c = b + 1; c < n; ++c)
					for (int d = c + 1; d < n; ++d)
						for (int e = d + 1; e < n; ++e)
							for (int f = e + 1; f < n; ++f)
								printf("%d %d %d %d %d %d\n", s[a], s[b], s[c], s[d], s[e], s[f]);
	}
	return 0;
}
