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
typedef vector<bool> vb;
typedef pair<int, int> pi;

#define fr(i,a,b) for (int i = a; i <= b; i++)
#define fr2(i,a,b) for (int i = a; i < b; i++)

int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");

	int n, m;
	cin >> n >> m;

	vector<vb> a(n + 1, vb(n + 1, false));
	fr2(i, 0, m) {
		int x, y;
		cin >> x >> y;

		a[x - 1][y - 1] = true;
		a[y - 1][x - 1] = true;
	}

	vi masks(n);
	fr2(i, 0, n) {
		int mask = 0;
		fr2(j, 0, n) {
			if (a[i][j]) {
				mask |= 1 << j;
			}
		}
		masks[i] = mask;
	}

	vi d(1 << n, 0);
	fr2(mask, 0, 1 << n) {
		fr2(i, 0, n) {
			if (!d[mask ^ (1 << i)]) d[mask ^ (1 << i)] = d[mask];

			if (!(mask & (1 << i)) && (masks[i] & mask == mask)) {
				d[mask ^ (1 << i)] = max(d[mask ^ (1 << i)], d[mask] + 1);
			}
		}
	}

	cout << d[(1 << n) - 1];

	return 0;
}
