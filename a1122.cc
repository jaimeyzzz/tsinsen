#include <cstdio>
#include <algorithm>
#include <vector>
#include <cfloat>

using namespace std;

typedef pair<float, float> Station;

int main() {
    vector<Station> s;
    float d1, c, d2, p;
    int n;
    scanf("%f%f%f%f%d", &d1, &c, &d2, &p, &n);
    s.push_back(Station(0.f, p));
    for (int i = 0; i < n; i ++) {
        float di, pi;
        scanf("%f%f", &di, &pi);
        s.push_back(Station(di, pi));
    }
    s.push_back(Station(d1, FLT_MAX));
    n += 2;
    sort(s.begin(), s.end(), [](const Station& a, const Station& b) {
        return a.first < b.first;
    });
    
    int cur_pos = 0;
    float cost = 0.f, cur_fuel = 0.f;
    while (cur_pos != n - 1) {
        bool cheaper = false;
        int next_pos = -1;
        float min_price = s[cur_pos].second;
        for (int i = cur_pos + 1; i < n; i ++) {
            if (s[i].first - s[cur_pos].first > c * d2) break;
            if (s[i].second < min_price) {
                cheaper = true;
                min_price = s[i].second;
                next_pos = i;
            }
            if (!cheaper) {
                next_pos = i;
            }
        }
        if (next_pos == -1) {
            printf("No Solution");
            return 0;
        }
        float fuel = (s[next_pos].first - s[cur_pos].first) / d2;
        if (cheaper) {
            if (cur_fuel < fuel) {
                cost += s[cur_pos].second * (fuel - cur_fuel);
                cur_fuel = 0.f;
            }
            else {
                cur_fuel -= fuel;
            }
        }
        else {
            float max_fuel = min(c, (d1 - s[cur_pos].first) / d2);
            cost += (max_fuel - cur_fuel) * s[cur_pos].second;
            cur_fuel = max_fuel - fuel;
        }
        cur_pos = next_pos;
    }
    printf("%.2f", cost);
    return 0;
}