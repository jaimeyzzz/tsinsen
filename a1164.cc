#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int m, n, k, l, d;
int row[1010], col[1010];

typedef pair<int, int> Talk;

int main() {
    cin >> m >> n >> k >> l >> d;
    for (int i = 0; i < d; i ++) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if (x == p) {
            col[min(y, q) - 1] ++;
        }
        else if (y == q) {
            row[min(x, p) - 1] ++;
        }
    }
    vector<Talk> r, c;
    for (int i = 0; i < m; i ++) {
        r.push_back(Talk(row[i], i));
    }
    for (int i = 0; i < n; i ++) {
        c.push_back(Talk(col[i], i));
    }
    sort(r.begin(), r.end(), [](const Talk& v1, const Talk& v2) {
        if (v1.first > v2.first) return true;
        return false;
    });
    sort(c.begin(), c.end(), [](const Talk& v1, const Talk& v2) {
        if (v1.first > v2.first) return true;
        return false;
    });
    vector<int> sa, ca;
    for (int i = 0; i < k; i ++) {
        sa.push_back(r[i].second + 1);
    }
    for (int i = 0; i < l; i ++) {
        ca.push_back(c[i].second + 1);
    }
    sort(sa.begin(), sa.end());
    sort(ca.begin(), ca.end());
    for (auto a : sa) cout << a << ' ';
    cout << endl;
    for (auto a : ca) cout << a << ' ';
    cout << endl;

    return 0;
}
