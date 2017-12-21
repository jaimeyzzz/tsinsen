#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> State;

int pe, decr;
double qe;
std::vector<State> s;
std::vector<double> q;

double quantity(int idx, int price) {
	if (idx + 1 < s.size()) {
		double p1 = s[idx].first, p2 = s[idx + 1].first, q1 = s[idx].second, q2 = s[idx + 1].second;
		return (q2 - q1) / (p2 - p1) * (price - p1) + q1;
	}
	else {
		return s.back().second - decr * (price - s.back().first);
	}
}

int main() {
	std::cin >> pe;
	while (true) {
		int p, q;
		std::cin >> p >> q;
		if (p == -1 && q == -1) break;
		s.push_back(State(p, q));
	}
	std::cin >> decr;
	sort(s.begin(), s.end(), [](const State& a, const State& b) {
		return a.first > b.second;
	});
	int min_price = s[0].first;
	pe -= min_price;
	for (auto& state : s) {
		state.first -= min_price;
	}

	for (int i = 0; i < s.size(); i ++) {
		if (i + 1 == s.size()) {
			int px;
			double qx;
			px = s[i].first, qx = s[i].second;
			while (qx > 0) {
				q.push_back(qx);
				if (px == pe) {
					qe = q.back();	
				}
				px ++;
				qx = quantity(i, px);
			}
			break;
		}
		for (int px = s[i].first; px < s[i + 1].first; px ++) {
			q.push_back(quantity(i, px));

			if (px == pe) {
				qe = q.back();	
			}
		}
	}

	double min_tax = -1e100, max_tax = 1e100;
	for (int px = 0; px < q.size(); px ++) {
		if (px == pe) continue;
		if (qe - q[px] > 0) {
			min_tax = std::max(min_tax, (px * q[px] - pe * qe) / (qe - q[px]));
		}
		else {
			max_tax = std::min(max_tax, (px * q[px] - pe * qe) / (qe - q[px]));
		}
	}
	if (std::ceil(min_tax) > std::floor(max_tax))
		std::cout << "NO SOLUTION";
	else {
		if (min_tax * max_tax < 0)
			std::cout << 0;
		else if (max_tax < 0) 
			std::cout << std::floor(max_tax);
		else if (min_tax > 0)
			std::cout << std::ceil(min_tax);
	}
	return 0;
}