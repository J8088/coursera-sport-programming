#include <algorithm>
#include <functional>
#include <cmath>
#include <limits>
#include <cfloat>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef int64_t I64;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

struct Order {
	int d; // дедлайн
	int c; // стоимость
};

inline bool operator<(const Order& a, const Order& b) {
	return a.c > b.c;
}

const int M = 5007;

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<Order> orders(n);
	fr2(i, 0, n) cin >> orders[i].d >> orders[i].c;

	sort(orders.begin(), orders.end());

	vector<bool> used(M, false);
	I64 sum = 0;
	fr2(i, 0, n) {
		int k = orders[i].d;
		while (k >= 1 && used[k]) k--;

		if (k < 1) continue;

		used[k] = true;
		sum += orders[i].c;
	}

	cout << sum;

	return 0;
}
