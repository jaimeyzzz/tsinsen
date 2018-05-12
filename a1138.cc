#include <algorithm>
#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>

using namespace std;

struct Vec {
	int x, y;

	Vec() { x = y = 0; }
	Vec(int x, int y) : x(x), y(y) {};
    Vec operator - (const Vec& v) {
        return Vec(x - v.x, y - v.y);
    }
    Vec operator + (const Vec& v) {
        return Vec(x + v.x, y + v.y);
    }
    int operator * (const Vec& v) {
        return v.x * x + v.y * y;
    }
    double length() {
        return sqrt(x * x + y * y);
    }
};

struct City {
	Vec p[4];
	int t;

    void find_airport() {
        for (int j = 0; j < 3; j ++) {
            int i = (j + 2) % 3, k = (j + 1) % 3;
            Vec v1 = p[i] - p[j], v2 = p[k] - p[j];
            if (v1 * v2 == 0) {
                p[3] = p[j] + v1 + v2;
                break;
            }
        }
    }
};

City cities[110];
double map[410][410];

int main() {
    int s, t, a, b;
    scanf("%d%d%d%d", &s, &t, &a, &b);
    for (int i = 0; i < s; i ++) {
        City& c = cities[i];
        for (int j = 0; j < 3; j ++) {
            scanf("%d%d", &c.p[j].x, &c.p[j].y);
        }
        scanf("%d", &c.t);
        c.find_airport();
    }
    for (int i = 0; i < s; i ++) {
        City& ci = cities[i];
        for (int k = 0; k < 4; k ++) {
            for (int kk = k + 1; kk < 4; kk ++) {
                double w = (ci.p[k] - ci.p[kk]).length() * ci.t;
                map[i * 4 + k][i * 4 + kk] = w;
                map[i * 4 + kk][i * 4 + k] = w;
            }
            for (int j = i + 1; j < s; j ++) {
                City cj = cities[j];
                for (int kk = 0; kk < 4; kk ++) {
                    double w = (ci.p[k] - cj.p[kk]).length() * t;
                    map[i * 4 + k][j * 4 + kk] = w;
                    map[j * 4 + kk][i * 4 + k] = w;
                }
            }
        }
    }
    for (int k = 0; k < 4 * s; k ++) {
        for (int i = 0; i < 4 * s; i ++) {
            for (int j = 0; j < 4 * s; j ++) {
                map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
            }
        }
    }
    double min_cost = std::numeric_limits<double>::max();
    for (int k = 0; k < 4; k ++) {
        for (int kk = 0; kk < 4; kk ++) {
            min_cost =
                min(min_cost, map[(a - 1) * 4 + k][(b - 1) * 4 + kk]);
        }
    }
    printf("%.1f", min_cost);
	return 0;
}
