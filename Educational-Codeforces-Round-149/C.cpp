#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	char buffer[3*100000 + 1];
	while (t--) {
		scanf("%s", buffer);
		string data;
		for (int i = 0; buffer[i]; ++i) data.push_back(buffer[i]);
		for (int i = data.size() - 1; i >= 0 && data[i] == '?'; --i) data[i] = '1';
		for (int i = 0; i < data.size() && (data[i] == '?' || data[i] == '0'); ++i) data[i] = '0';
		int prev = -1;
		for (int i = 0; i < data.size(); ++i) {
			if (prev == -1 && data[i] == '?') prev = i - 1;
			else if (prev != -1 && data[i] != '?') {
				char toset = '1';
				if (data[prev] == data[i] && data[i] == '0') toset = '0';
				for (int j = prev + 1; j < i; ++j) data[j] = toset;
				prev = -1;
			}
		}
		for (auto &i : data) printf("%c", i);
		printf("\n");
	}
	return 0;
}
