//https://codeforces.com/gym/104314/problem/E

#include <bits/stdc++.h>

using namespace std;

struct Point {
	long x, y, z;
};

long n, m, mn;

bool compare_x(Point &a, Point &b) {
	return a.x < b.x ? 1 : a.y < b.y;
}

bool compare_y(Point &a, Point &b) {
	return a.y < b.y ? 1 : a.x < b.x;
}

long dist(Point &a, Point &b) {
	if (a.z == b.z) return n + m + 10;
	return abs(a.x - b.x) + abs(a.y - b.y);
}

void brute_force(Point points[], long size) {
	for (int i = 0; i < size; ++i) for (int j = i + 1; j < size; ++j) mn = min(mn, dist(points[i], points[j]));
}

void strip_closest(Point strip[], long size) {
	for (int i = 0; i < size; ++i) for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < mn; ++j) mn = min(mn, dist(strip[i], strip[j]));
}

void closest_util(Point p_x[], Point p_y[], long size) {
	if (size < 4) {
		brute_force(p_x, size);
		return;
	}
	long mid = size >> 1;
	Point mid_point = p_x[mid];

	Point p_yl[mid];
	Point p_yr[size-mid];
	long li = 0, ri = 0;
	
	for (long i = 0; i < size; i++) {
		if ((p_y[i].x < mid_point.x || (p_y[i].x == mid_point.x && p_y[i].y < mid_point.y)) && li < mid) p_yl[li++] = p_y[i];
		else p_yr[ri++] = p_y[i];
	}

	closest_util(p_x, p_yl, mid);
	closest_util(p_x + mid, p_yr, size-mid);
	Point strip[size];
	long j = 0;

	for (long i = 0; i < n; i++) if (abs(p_y[i].x - mid_point.x) < mn) {
		strip[j] = p_y[i];
		++j;
	}
	strip_closest(strip, j);
}

long closest(vector<Point> &points) {
	Point p_x[points.size()];
	Point p_y[points.size()];
	for (int i = 0; i < points.size(); ++i) {
		p_x[i] = points[i];
		p_y[i] = points[i];
	}
	mn = m + n + 10;
	sort(p_x, p_x + points.size(), compare_x);
	sort(p_y, p_y + points.size(), compare_y);
	closest_util(p_x, p_y, points.size());
	return mn;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long id = 0;
	cin >> n >> m;
	string data[n + 2];
	string temp = "";
	for (int i = 0; i < m; ++i) temp.push_back('0');
	data[0] = temp;
	for (long i = 1; i < n + 1; ++i) {
		cin >> data[i];
		data[i].push_back('0');
		data[i].insert(data[i].begin(), '0');
	}
	data[n + 1] = temp;
	long datap[n + 2][m + 2];
	for (auto &f : datap) for (auto &c : f) c = 0;

	vector<Point> points;

	for (long i = 1; i < n + 1; ++i) for (long j = 1; j < m + 1; ++j) if (data[i][j] == '1' && !datap[i][j]) {
		++id;
		stack<pair<long, long>> s;
		s.push({i, j});
		pair<long, long> t;
		while (!s.empty()) {
			t = s.top();
			s.pop();
			if (data[t.first][t.second + 1] == '0' || data[t.first + 1][t.second] == '0' || data[t.first][t.second - 1] == '0' || data[t.first][t.second + 1] == '0') points.push_back({t.first, t.second, id});
			datap[t.first][t.second] = id;
			if (data[t.first - 1][t.second] == '1' && !datap[t.first - 1][t.second]) s.push({t.first - 1, t.second});
			if (data[t.first + 1][t.second] == '1' && !datap[t.first + 1][t.second]) s.push({t.first + 1, t.second});
			if (data[t.first][t.second - 1] == '1' && !datap[t.first][t.second - 1]) s.push({t.first, t.second - 1});
			if (data[t.first][t.second + 1] == '1' && !datap[t.first][t.second + 1]) s.push({t.first, t.second + 1});
		}
	}
	cout << closest(points) - 1 << '\n';
	return 0;
}
