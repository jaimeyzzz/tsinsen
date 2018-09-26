#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int m, n, k;
typedef pair<int, int> Peanut;
vector<Peanut> p;

bool timeout(int cost, int x) {
    if (cost + x + 1 > k)
        return true;
    return false;
}

int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < m; i ++)
        for (int j = 0; j < n; j ++) {
            int pn;
            cin >> pn;
            p.push_back(Peanut(pn, i * n + j));
        }

    sort(p.begin(), p.end(), [](const Peanut& a, const Peanut& b) {
        if (a.first == b.first) {
            if (a.second < b.second) {
                return true;
            }
        }
        if (a.first > b.first) {
            return true;
        }
        return false;
    });
    for (size_t i = 0; i < p.size(); i ++) {

    }

    int s = 0, c = 0, lx = -1, ly = -1;
    for (size_t i = 0; i < p.size(); i ++) {
        //cout << pt.first << ' ' << pt.second << endl;
        Peanut pt = p[i];
        int r = pt.first;
        int x = pt.second / n;
        int y = pt.second % n;
        if (r == 0) break;

        if (i == 0) {
            c += x + 2;
        }
        else {
            c += abs(x - lx) + abs(y - ly) + 1;
        }
        if (timeout(c, x)) {
            break;
        }
        lx = x, ly = y;
        s += r;
    }
    cout << s << endl;

    return 0;
}
