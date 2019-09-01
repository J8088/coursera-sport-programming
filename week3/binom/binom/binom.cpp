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

int main() {
	ios_base::sync_with_stdio(false);

	int n0, k0;
	cin >> n0 >> k0;

	vector<I64> cprev(n0 + 1, 0), c(n0 + 1, 0);
	cprev[0] = cprev[1] = 1;
	fr(n, 0, n0) {
		c[0] = c[n] = 1;
		fr2(k, 1, n) {
			c[k] = cprev[k - 1] + cprev[k];
		}
		cprev = c;
	}

	cout << c[k0];

	return 0;
}
