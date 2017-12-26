#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct City {
	int x[4], y[4];
	int t;
}

void ComputeCity(City& c) {
	for (int j = 0; j < 3; j ++) {
		
	}
}

int s, t, a, b;
vector<city> cities;

int main() {
	cin >> s >> t >> a >> b;	
	for (int i = 0; i < s; i ++) {
		City c;
		for (int j = 0; j < 3; j ++) {
			cin >> c.x[j] >> c.y[j];
		}

		cities.push_back(c);
	}
	return 0;
}