#include <iostream>
#include <string>

using namespace std;

string mid, lat;

void search(int ms, int me, int ls, int le) {
    if (ms > me || ls > le) return;
    if (ms == me && ls == le) {
        cout << mid[ms];
        return;
    }

    char root = lat[le];
    int idx;
    for (idx = ms; idx <= me; idx++) {
        if (mid[idx] == root) {
            break;
        }
    }
    cout << root;
    search(ms, idx - 1, ls, ls + idx - ms - 1);
    search(idx + 1, me, ls + idx - ms, le - 1);
}

int main() {
    cin >> mid >> lat;
    search(0, mid.length() - 1, 0, lat.length() - 1);
    return 0;
}
