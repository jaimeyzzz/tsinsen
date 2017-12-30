#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Vec {
	Vec() { x = y = 0; }
	Vec(int x, int y) : x(x), y(y) {};
	
	int x, y;
};

Vec operator - (const Vec& v1, const Vec& v2) {
	return Vec(v1.x - v2.x, v1.y - v2.y);
}
Vec operator + (const Vec& v1, const Vec& v2) {
	return Vec(v1.x + v2.x, v1.y + v2.y);
}
int operator * (const Vec& v1, const Vec& v2) {
	return v1.x * v2.x + v1.y * v2.y;
}

struct City {
	Vec p[4];
	int t;
};

void FindAirport(City& c) {
	for (int j = 0; j < 3; j ++) {
		int i = (j - 1) % 3, k = (j + 1) % 3;
		Vec v1 = c.p[i] - c.p[j], v2 = c.p[k] - c.p[j];
		if (v1 * v2 == 0) {
			c.p[3] = c.p[j] + v1 + v2;
			break;
		}
	}
}

int main() {
	int n;
	cin >> n;
	while (n --) {
		int s, t, a, b;
		vector<City> cities;
		cin >> s >> t >> a >> b;	
		for (int i = 0; i < s; i ++) {
			City c;
			for (int j = 0; j < 3; j ++) {
				cin >> c.p[j].x >> c.p[j].y >> c.t;
			}
			cities.push_back(c);
		}		
	}
	return 0;
}