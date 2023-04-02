#include <bits/stdc++.h>

using namespace std;

const int p1 = 257;
const int p2 = 127;
const int m = 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b;
	cin >> a >> b;
	while (a|b) {
		string d[a];
		string d1[b];
		getline(cin, d[0]);
		for (int i = 0; i < a; ++i) getline(cin, d[i]);
		map<long long, set<long long>> d2;
		map<long long, set<long long>> d3;
		long long hash1, hash2, p1_pow, p2_pow;
		int f = a - b + 1, g, gp;
		for (int i = 0; i < f; ++i) for (int j = 0; j < f; ++j) {
			hash1 = 0;
			hash2 = 0;
			p1_pow = 1;
			p2_pow = 1;
			g = 0; gp = 0;
			while (gp < b) {
				hash1 = (hash1 + (d[i + gp][j + g] + 1)*p1_pow)%m;
				hash2 = (hash2 + (d[i + gp][j + g] + 1)*p2_pow)%m;
				p1_pow = (p1_pow*p1)%m;
				p2_pow = (p2_pow*p2)%m;
				++g;
				gp += g == b ? 1 : 0;
				g = g != b ? g : 0;
			}
			if (!d2.count(hash1)) d2[hash1] = {};
			d2[hash1].insert(100000*i + j);
			if (!d3.count(hash2)) d3[hash2] = {};
			d3[hash2].insert(100000*i + j);
		}
		for (int i = 0; i < b; ++i) getline(cin, d1[i]);
		long long hash11 = 0, hash21 = 0, hash31 = 0, hash41 = 0;
		long long hash12 = 0, hash22 = 0, hash32 = 0, hash42 = 0;
		p1_pow = 1;
		p2_pow = 1;
		g = 0;
		gp = 0;
		int b1 = b - 1;
		while (gp < b) {
			hash11 = (hash11 + (d1[gp][g] + 1)*p1_pow)%m;
			hash21 = (hash21 + (d1[b1 - g][gp] + 1)*p1_pow)%m;
			hash31 = (hash31 + (d1[b1 - gp][b1 - g] + 1)*p1_pow)%m;
			hash41 = (hash41 + (d1[g][b1 - gp] + 1)*p1_pow)%m;
			hash12 = (hash12 + (d1[gp][g] + 1)*p2_pow)%m;
			hash22 = (hash22 + (d1[b1 - g][gp] + 1)*p2_pow)%m;
			hash32 = (hash32 + (d1[b1 - gp][b1 - g] + 1)*p2_pow)%m;
			hash42 = (hash42 + (d1[g][b1 - gp] + 1)*p2_pow)%m;
			p1_pow = (p1_pow*p1)%m;
			p2_pow = (p2_pow*p2)%m;
			++g;
			gp += g == b ? 1 : 0;
			g = g != b ? g : 0;
		}
		set<long long> s1;
		set<long long> s2;
		set<long long> s3;
		set<long long> s4;
		if (d2.count(hash11) && d3.count(hash12)) set_intersection(d2[hash11].begin(), d2[hash11].end(), d3[hash12].begin(), d3[hash12].end(), inserter(s1, s1.end()));
		if (d2.count(hash21) && d3.count(hash22)) set_intersection(d2[hash21].begin(), d2[hash21].end(), d3[hash22].begin(), d3[hash22].end(), inserter(s2, s2.end()));
		if (d2.count(hash31) && d3.count(hash32)) set_intersection(d2[hash31].begin(), d2[hash31].end(), d3[hash32].begin(), d3[hash32].end(), inserter(s3, s3.end()));
		if (d2.count(hash41) && d3.count(hash42)) set_intersection(d2[hash41].begin(), d2[hash41].end(), d3[hash42].begin(), d3[hash42].end(), inserter(s4, s4.end()));
		cout << s1.size() << ' ' << s2.size() << ' ' << s3.size() << ' ' << s4.size() << '\n';
		cin >> a >> b;
	}
	return 0;
}
