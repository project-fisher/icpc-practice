#include <bits/stdc++.h>
#define ull unsigned long long
#define ul unsigned long
#define ui unsigned int

using namespace std;

int main() {
	char bS[200003]; scanf("%s", bS);
	char bT[200003]; scanf("%s", bT);
	vector<pair<char, int>> fS = {{bS[0], 1}}, fT = {{bT[0], 1}};
	for (int i = 1; bS[i]; ++i) {
		if (bS[i] == fS.back().first) ++fS.back().second;
		else fS.push_back(make_pair(bS[i], 1));
	}
	for (int i = 1; bT[i]; ++i) {
		if (bT[i] == fT.back().first) ++fT.back().second;
		else fT.push_back(make_pair(bT[i], 1));
	}
	bool ans = fS.size() == fT.size();
	for (int i = 0; ans && i < fS.size(); ++i) ans = fS[i].first == fT[i].first && (fS[i].second == fT[i].second || (fS[i].second < fT[i].second && fS[i].second > 1));
	printf(ans ? "Yes\n" : "No\n");
	return 0;
}
