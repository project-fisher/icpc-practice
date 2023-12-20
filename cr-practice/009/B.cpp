#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long

using namespace std;

int main() {
	char S[102], T[102]; scanf("%s%s", S, T);
	int s = strlen(S), t = strlen(T);
	bool ans = 0;
	for (int i = 0; t <= s - i && !ans; ++i) {
		bool p = 1;
		for (int k = 0, j = i; p && k < t; ++k, ++j) p = S[j] == T[k];
		ans = p;
	}
	if (ans) puts("Yes");
	else puts("No");
	return 0;
}
