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

struct Thing {
	int c, w;
};

inline bool operator<(const Thing& a, const Thing& b) {
	return a.c / a.w > b.c / b.w;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, W;
	cin >> n >> W;
	
	vector<Thing> t(n);
	fr2(i, 0, n) cin >> t[i].w >> t[i].c;

	sort(t.begin(), t.end());

	I64 sum = 0;
	int cw = 0;
	fr2(i, 0, n) {
		if (W - cw >= t[i].w) {
			sum += t[i].c;
			cw += t[i].w;
		} else {
			sum += (W - cw) * (t[i].c / t[i].w);
			break;
		}
	}

	cout << sum;

	return 0;
}
