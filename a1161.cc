#include <iostream>

using namespace std;

int m, s, t;

int main() {
    cin >> m >> s >> t;

    int s_tot = 0;
    int t_rest = t, m_rest = m;

    while (true) {
        if (m_rest >= 10) {
            t_rest -= 1;
            m_rest -= 10;
            s_tot += 60;
        }
        else if (m_rest >= 6) {
            if (t_rest >= 2 && s - s_tot > 17) {
                t_rest -= 2;
                m_rest -= 6;
                s_tot += 60;
            }
            else {
                t_rest -= 1;
                s_tot += 17;
            }
        }
        else if (m_rest >= 2) {
            if (t_rest >= 3 && s - s_tot > 34) {
                t_rest -= 3;
                m_rest -= 2;
                s_tot += 60;
            }
            else {
                s_tot += 17;
                t_rest -= 1;
            }
        }
        else {
            if (t_rest >= 7 && s - s_tot > 102) {
                t_rest -= 7;
                s_tot += 120;
            }
            else {
                s_tot += 17;
                t_rest -= 1;
            }
        }
        if (s_tot >= s && t_rest >= 0) {
            cout << "Yes" << endl;
            cout << t - t_rest;
            return 0;
        }
        else if (s_tot < s && t_rest == 0) {
            cout << "No" << endl;
            cout << s_tot;
            return 0;
        }
    }
    return 0;
}
