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

struct Request {
	int l, r;
};

inline bool operator<(const Request& a, const Request& b) {
	return a.r < b.r;
}

int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");

	int n;
	cin >> n;

	vector<Request> requests(n);
	fr2(i, 0, n) cin >> requests[i].l >> requests[i].r;

	sort(requests.begin(), requests.end());

	multiset<int, greater<int>> rooms = { requests[0].r };
	fr2(i, 1, n) {
		auto it = rooms.lower_bound(requests[i].l);
		if (it != rooms.end()) {
			rooms.erase(it);
		}
		rooms.insert(requests[i].r);
	}

	cout << rooms.size();

	return 0;
}
