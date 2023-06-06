#include <bits/stdc++.h>
#define llu unsigned long long
#define ll long long

using namespace std;

int main() {
	map<char, int> data;
	char c;
	while ((c = getchar()) <= 'z' && c >= 'a') data[c]++;
	bool found = 0;
	for (auto &i : data) if (i.second == 1) {
		printf("%c\n", i.first);
		found = 1;
		break;
	}
	if (!found) printf("-1\n");
	return 0;
}
