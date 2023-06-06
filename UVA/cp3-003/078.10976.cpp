// 0.000s/3392
#include <bits/stdc++.h>

using namespace std;

int main() {
	long k;
	while (scanf("%ld", &k) == 1) {
		long y = k + 1;
		vector<long> f = {y};
		long sk = k << 1;
		while (y++ < sk) if (y*k%(y - k) == 0) f.emplace_back(y);
		printf("%ld\n", f.size());
		for (auto &i : f) printf("1/%ld = 1/%ld + 1/%ld\n", k, i*k/(i - k), i);
	}
	return 0;
}
