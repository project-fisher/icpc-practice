#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define lu unsigned long

using namespace std;

int main() {
	lu H, W; scanf("%lu%lu", &H, &W);
	vector<string> S(W); 
	for (int i = 0; i < H; ++i) {
		while (getchar() != '\n');
		for (int j = 0; j < W; ++j) S[j].push_back(getchar());
	}
	vector<string> T(W); 
	for (int i = 0; i < H; ++i) {
		while (getchar() != '\n');
		for (int j = 0; j < W; ++j) T[j].push_back(getchar());
	}
	unordered_multiset<string> sets, sett;
	for (auto &i : S) sets.insert(i);
	for (auto &i : T) sett.insert(i);
	if (sets == sett) puts("Yes");
	else puts("No");
	return 0;
}
